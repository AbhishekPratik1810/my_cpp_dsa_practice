/*
You are given an array A1 of integers. You have to form first Binary Search tree and then you are provided another array A2. You have to delete each node from the BST which is present in the array A2. Now you have to print preorder traversal of the tree. It is assured that the elements of array A2 will be present in the tree.
Note : In case of node with 2 children, consider its inorder successor as its replacement.
Input Format

First line contains integer t as number of test cases.
Each test case contains four lines. First line contains integer n which represents the length of the array A1 and next line contains n space separated integers denoting the elements of array A1. Similarly third line contains integer m which represents the length of the array A2 and next line contains m space separated integers denoting the elements of array A2.


1 < t < 100
1< n,m < 1000

Sample Input
1
7
5 3 2 4 7 6 8
3
2 3 5

Sample Output
6 4 7 8

*/

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left =NULL;
    Node* right = NULL;
    Node(int val){
        data=val;
        left=NULL;
        right = NULL;
    }
};

Node* buildTree(int element,Node* root){
    if(!root){
        return new Node(element);
    }
    if(element>root->data) root->right = buildTree(element,root->right);
    else if(element<=root->data) root->left = buildTree(element,root->left);

    return root;
}

Node* deleteNode(int tbd, Node* root){
    if(!root) return NULL;

    if(root->data==tbd){

        if(!root->left && !root->right)
            return NULL;

        if(root->right && root->left){
            Node* temp = root->right;
            while(temp->left)
                temp=temp->left;

            temp->right = deleteNode(temp->data,root->right);
            temp->left = root->left;
            return temp;
        }
        return root->right ? root->right : root->left;


    }else if(root->data < tbd)
        root->right = deleteNode(tbd,root->right);
    else
        root->left = deleteNode(tbd,root->left);


    return root;

}

void preOrder(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


int main(){

    int t; cin>>t;

    while(t--){
        int n,m; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        cin>>m;
        int toDelete[m];
        for(int i=0;i<m;i++)
            cin>>toDelete[i];

        Node* root = NULL;
        for(int i=0;i<n;i++)
            root = buildTree(arr[i],root);

        for(int i=0;i<m;i++)
            root = deleteNode(toDelete[i],root);

        preOrder(root);

    }
}

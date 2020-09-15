#include<iostream>
using namespace std;

typedef struct NODE{
    int data;
    NODE* left;
    NODE* right;
}NODE;

//Currently I know how to insert in BST only, hence inserted in BST. The method to find height though, is in general for any binary tree
NODE* insertInBST(int,NODE*);
int getHeight(NODE*);

int main(){
    int arr[]={10,21,45,13,87,24,19,22};
    NODE* root = NULL;                                   //You can access memory in Heap only using pointers.
                                                        //Also, it is important to declare it NULL, else it will go into the else condition of the insert function and cause runtime error
    for(int i=0;i<8;i++)
        root=insertInBST(arr[i],root);

    cout<<"Height is "<<getHeight(root)<<endl;
}


NODE* insertInBST(int data, NODE* currentNode){
    if(currentNode==NULL){
        NODE* node = new NODE;
        node->data=data; node->left=node->right=NULL;
        currentNode=node;
    }else{
        if(data<=currentNode->data)
            currentNode->left = insertInBST(data,currentNode->left);
        else
            currentNode->right = insertInBST(data,currentNode->right);
    }
    return currentNode;
}

/*
People use 2 definitions for height
i) The length of the longest path from root of a tree to any of it's leaf
    Here, the height of a leaf = 0 (note height of a leaf is height of the tree where the leaf is a root, i.e since it has no children, longest path encountered = 0)
    and the height of an empty tree is -1
ii) The max number of nodes encountered while going from root to any of tree's leaf
    Here, the height of a leaf is 1(note height of a leaf is height of the tree where the leaf is a root, i.e since it has no children, max nodes encountered = 1)
    and the height of an empty tree is 0

In below example, we take the 1st definition for the height of a tree
*/
int getHeight(NODE* current){
    if(current==NULL)
        return -1;
    else{
        int t1=1+getHeight(current->right);
        int t2=1+getHeight(current->left);
        return max(t1,t2);
    }
}



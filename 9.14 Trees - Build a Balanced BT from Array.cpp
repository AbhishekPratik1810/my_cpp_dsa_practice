//https://practice.geeksforgeeks.org/problems/array-to-bst/0

#include <iostream>
using namespace std;

struct Node{

  int data;
  Node* left = NULL;
  Node* right = NULL;

};

Node* createNode(int val){
    Node* node = new Node;
    node->data=val;
    return node;
}

Node* buildTree(int arr[], int beg,int end){

     if(beg>end)                //happens when we call for a leaf node
        return NULL;

     int mid = (beg+end)/2;
     Node* rightSubtree = buildTree(arr,mid+1,end);
     Node* leftSubtree = buildTree(arr,beg,mid-1);

     Node* curr = createNode(arr[mid-1]);
     curr->left = leftSubtree;
     curr->right = rightSubtree;

     return curr;

}

void preOrder(Node* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void deleteTree(Node* root){
    if(root==NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void print(int arr[],int beg, int end){

    if(beg>end) return;

    int mid = (beg+end)/2;
    cout<<arr[mid-1]<<" ";
    print(arr,beg,mid-1);
    print(arr,mid+1,end);

}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++) cin>>arr[i];

	    //Without building the tree
	    /*
	    print(arr,1,n);
	    cout<<endl;
	    */

	    Node* root = buildTree(arr,1,n);

	    preOrder(root);
	    cout<<endl;
	    deleteTree(root);

	}
	return 0;
}

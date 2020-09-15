/*
Observation: Only Inorder Traversal alone will never give me a UNIQUE BT
Consider Inorder Traversal as : 2 3 1
This can be made using both the given trees
         1              1
        /              /
       2              3
        \            /
         3          2

From preorder array, we get the information of the root of the tree

*/

//https://practice.geeksforgeeks.org/problems/construct-tree-1/1


/*
    Assume, NO Duplicates, and assume that data given is correct
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

map<int,int> pos;

int getPreEnd(int inStart,int inEnd,int preStart){
    return inEnd-inStart+preStart;
}


Node* buildRec(int in[], int pre[], int inStart, int inEnd, int preStart, int preEnd){

    if(inStart>inEnd || preStart>preEnd)
        return NULL;

    Node* curr = new Node(pre[preStart]);

    int inPos = pos[pre[preStart]];
    int leftPreEnd = getPreEnd(inStart,inPos-1,preStart+1);

    curr->left = buildRec(in,pre,inStart,inPos-1,preStart+1,leftPreEnd);
    curr->right = buildRec(in,pre,inPos+1,inEnd, leftPreEnd+1,preEnd);

    return curr;

}


Node* buildTree(int in[],int pre[], int n)
{

    pos.clear();

    for(int i=0;i<n;i++)
        pos[in[i]] = i;

    return buildRec(in,pre,0,n-1,0,n-1);


}

void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];

		Node *root = buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}


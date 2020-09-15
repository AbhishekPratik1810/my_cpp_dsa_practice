// https://practice.geeksforgeeks.org/problems/construct-tree-from-inorder-and-levelorder/1/
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;

	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
map<int,int> pos;

Node* buildRec(int in[], int lev[], int inStart, int inEnd, int cPos){

    if(inStart>inEnd)
        return NULL;

    Node* curr = new Node(lev[cPos]);
    int inPos = pos[lev[cPos]];

    curr->left = buildRec(in,lev,inStart,inPos-1,cPos*2 + 1);
    curr->right = buildRec(in,lev,inPos+1,inEnd,cPos*2 + 2);

    return curr;

}


Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{

    pos.clear();

    for(int i=0;i<n;i++)
        pos[inorder[i]] = i;

    return buildRec(inorder,levelOrder,0,n-1,0);

}

void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);

}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}


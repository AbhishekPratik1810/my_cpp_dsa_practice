/*
5
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
65
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
100
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
30
4
78 34 L 78 97 R 34 12 L 34 45 R
34
5
78 80 R 78 24 L 24 18 L 24 55 R 80 85 R
40

https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
*/

#include <iostream>
#include<stack>
using namespace std;

// BST Node
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

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cout<<"Test Cases : ";
    cin>>t;
    cout<<endl;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
    cout<<"Answer is ";
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl<<endl;
	else
	cout << " "<<"-1"<<endl<<endl;
    }
	return 0;
}// } Driver Code Ends


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    if(root==NULL)
        return;
    else{
        stack<Node*>st;
        while(!st.empty() || root){
            if(root){
                if(root->key<key){
                    if(pre && pre->key<root->key){
                        pre=root;
                    }else if(!pre)
                        pre=root;
                }else if(root->key>key){
                    if(suc && root->key<suc->key)
                        suc=root;
                    else if(!suc)
                        suc=root;
                }

                st.push(root);
                root=root->left;
            }else{
                root=st.top()->right;
                st.pop();
            }
        }
    }


}

void findPreSucRecursive(Node* root, Node*& pre, Node*& suc, int key)
{

    if(root!=NULL){
        if(root->key>key){
            findPreSucRecursive(root->left,pre,suc,key);
            if(!suc)
                suc=root;
        }
        else if(root->key<key){
            findPreSucRecursive(root->right,pre,suc,key);
            if(!pre)
                pre=root;
        }else{
            findPreSucRecursive(root->left,pre,suc,key);
            if(!pre)
                pre=root->left;
            findPreSucRecursive(root->right,pre,suc,key);
            if(!suc)
                suc=root->right;
        }
    }



}

#include<iostream>
#include<queue>
#include<stack>
#include<map>
using namespace std;

typedef struct NODE{
    int data;
    NODE* left;
    NODE* right;
}NODE;

NODE* insertInBST(int,NODE*);
NODE* deleteNODE(NODE*,int);
NODE* recDeleteNODE(NODE*,int);

void badhiyaLOT(NODE*);
int main(){
    int arr[]={10,21,45,13,87,24,8,3,1,5,19,22};
    NODE* root = NULL;                                   //You can access memory in Heap only using pointers.
                                                         //Also, it is important to declare it NULL, else it will go into the else condition of the insert function and cause runtime error
    for(int i=0;i<12;i++)
        root=insertInBST(arr[i],root);

    badhiyaLOT(root);cout<<endl;
    root = deleteNODE(root,21);
    badhiyaLOT(root);
}


NODE* insertInBST(int data, NODE* currentNODE){
    if(currentNODE==NULL){
        NODE* node = new NODE;
        node->data=data; node->left=node->right=NULL;
        currentNODE=node;
    }else{
        if(data<=currentNODE->data)
            currentNODE->left = insertInBST(data,currentNODE->left);
        else
            currentNODE->right = insertInBST(data,currentNODE->right);
    }
    return currentNODE;
}


/*
Badhiya Idea
What is the return type? Well, return the updated link after the deletion has taken place, maybe NULL (if deleted leaf) or the same link as before, or an updated link
If you find the node which is to be deleted, then mark the left and right child of that node
Let curr       = node to be removed
    leftChild  = left child of curr
    rightChild = right child of curr

If(rightChild)
    => return rightChild. why? because we can easily connected the right child to the parent of curr as parent<rightChild by BST logic and curr is deleted this way too
    Link leftChild of curr to the extreme left of rightChild
Else
    => no rightChild, => simply link the parent to the left Child of the curr , i.e return left Child

*/
Node* leftChild;
Node* rightChild;


Node* dfs(Node* root, int key){
    if(!root) return NULL;

    if(root->data == key){
        leftChild = root->left, rightChild = root->right;
        if(rightChild) return rightChild;
        return leftChild;
    }

    root->left = dfs(root->left,key);
    root->right = dfs(root->right,key);

    return root;
}


// Return the root of the modified BST after deleting the node with value X
Node *deleteNodebadhiyaWala(Node *root,  int X)
{
    leftChild=NULL, rightChild=NULL;
    Node* newRoot = dfs(root,X);
    if(rightChild){
        //Inorder Successor
        while(rightChild->left)
            rightChild=rightChild->left;
        rightChild->left = leftChild;
    }
    return newRoot;
}

NODE* found(NODE* root, int X, map<int,NODE*> &mp){
    if(root==NULL)
        return root;
    if(root->data==X)
        return root;
    mp[0]=root;
    if(root->data>X)
        return(found(root->left,X,mp));
    return(found(root->right,X,mp));
}

NODE* getLowest(NODE* root){
    while(root->left!=NULL)
        root=root->left;
    return root;
}


/*
    Sasta Idea :
    If such an element doesn't exist, then return the current node
    Else
        keep a track of the previous node which connected to the current node
        Now if prev=NULL => the node to be deleted is the initial root node, hence handle this case separately using logic mentioned below
        If node to be deleted has no child, then simply remove the link from previous to the current node
        If node to be deleted has 1 child, then change the link from prev to the child of the current node
        If node to be deleted has 2 childs
            Find the minimum element(i.e left most element) in the right child of current
            Link the minimum element with the left child of current
            Link prev to the right child of current
*/
NODE *deleteNODE(NODE *root,  int X)
{
    NODE* prev=NULL;
    NODE* current;
    map<int,NODE*> mp;
    mp[0]=prev;
    mp[1]=root;
    current = found(root,X,mp);
    prev=mp[0];
    if(current==NULL){
        return root;
    }
    else{
        if(prev==NULL){
            if(current->right==NULL)
                return current->left;
            if(current->left==NULL)
                return current->right;
            root=current->right;
            NODE* lowest = getLowest(root);
            lowest->left=current->left;
            return root;
        }
        if(current->left==NULL && current->right==NULL){
            if(prev->data<current->data)
                prev->right=NULL;
            else
                prev->left=NULL;
        }else if(current->left==NULL){
            if(prev->data<current->data)
                prev->right=current->right;
            else
                prev->left=current->right;
        }else if(current->right==NULL){
            if(prev->data<current->data)
                prev->right=current->left;
            else
                prev->left=current->left;
        }else{
            NODE* lowest = getLowest(current->right);
            lowest->left=current->left;
            if(prev->data<current->data)
                prev->right=current->right;
            else
                prev->left=current->right;
        }
    }
    return root;
}

NODE* recDeleteNODE(NODE* root, int X){

}

void badhiyaLOT(NODE* current){
    if(current==NULL)
        return;
    else{
        queue<NODE*> q;
        q.push(current);
        while(!q.empty()){
            current=q.front();
            cout<<current->data<<" ";
            if(current->left!=NULL)q.push(current->left);
            if(current->right!=NULL)q.push(current->right);
            q.pop();
        }
    }
}





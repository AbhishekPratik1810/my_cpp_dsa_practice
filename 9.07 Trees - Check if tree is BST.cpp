#include<iostream>
#include<queue>
#include<stack>
using namespace std;

typedef struct NODE{
    int data;
    NODE* left;
    NODE* right;
}NODE;

//Currently I know how to insert in BST only, hence inserted in BST. The checking method though, is in general for any binary tree
NODE* insertInBST(int,NODE*);

bool checkIfBST(NODE*);
int minBST(NODE*);
int maxBST(NODE*);
bool elegantCheck(NODE*,int,int);
bool checkIfBSTItr(NODE*);

int main(){
    int arr[]={10,21,45,13,87,24,8,3,1,5,19,22};
    NODE* root = NULL;                                   //You can access memory in Heap only using pointers.
                                                         //Also, it is important to declare it NULL, else it will go into the else condition of the insert function and cause runtime error
    for(int i=0;i<12;i++)
        root=insertInBST(arr[i],root);

    cout<<(checkIfBST(root)?"YES":"NO")<<endl;
    cout<<(elegantCheck(root,INT_MAX,INT_MIN)?"YES":"NO")<<endl;
    cout<<(checkIfBSTItr(root)?"YES":"NO")<<endl;
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

//O(n^2)
bool checkIfBST(NODE* current){
    if(current==NULL)
        return true;
    else{
        int rightMin=minBST(current->right),leftMax=maxBST(current->left);                 //current->data must be >= the leftmost maximum and < the rightmost minimum
        bool ok = (current->data<rightMin && current->data>=leftMax)?1:0;
        return ok && checkIfBST(current->left) && checkIfBST(current->right);
    }
}

/*
    Best Case (Perfect BT) : O(n), Worst Case(unary or skewed tree) : 0(n) , either way it's O(n) using Master's Theorem
    Note for unary tree, T(n)=T(n-1), one of the other statement in minBST(curr->right) or min BST(curr->left) always runs in constant time,
    as one of curr->right or curr->left is always null, corresponding to the base condition of the recursion
    For perfect BT T(n) = 2T(n/2)
*/
int minBST(NODE* current){
    if(current==NULL)
        return INT_MAX;
    else
        return min(min(minBST(current->right),minBST(current->left)),current->data);

}

//Same analysis for minBST leads to O(n) over here
int maxBST(NODE* current){
    if(current==NULL)
        return INT_MIN;
    else
        return max(max(maxBST(current->right),maxBST(current->left)),current->data);

}

bool elegantCheck(NODE* current,int topRight, int topLeft){                 //topRight is the nearest parent to the right of a node, topLeft is nearest parent to the left of the node
    if(!current) return true;                   //empty tree => BST
    else{
        bool ok = (current->data<=topRight && current->data>topLeft)?1:0;
        return ok && elegantCheck(current->left,current->data,topLeft) && elegantCheck(current->right,topRight,current->data);
    }
}

//In order traversal in BST gives the Tree in sorted order
bool checkIfBSTItr(NODE* current){
    if(!current) return true;
    stack<NODE*> st;
    int prev=INT_MIN,curr;
    bool onRHS=false;
    while(!st.empty() || current){
        if(current){
            st.push(current);
            current=current->left;
        }else{
            curr=st.top()->data;
            if((onRHS && curr<=prev)||(!onRHS && curr<prev)) return false;
            current=st.top()->right;
            st.pop();
            prev=curr;
            onRHS = current ? 1 : 0;
        }
    }
    return true;
}


bool ok;

int helper2(Node* root){
    if(!root) return INT_MIN;

    int maxLeft = helper2(root->left);
    int maxRight = helper2(root->right);

    ok = ok && maxLeft<root->data && (maxRight==INT_MIN || maxRight>root->data);
    return max({maxLeft,maxRight,root->data});
}

bool isBST(Node* root) {
    ok = 1;
    helper2(root);
    return ok;
}


long long maxM = 1e18;
long long minM = -1e18;


bool isBST(Node* current, long long upperBound, long long lowerBound){

    if(!current)
        return 1;

    return current->data<upperBound && current->data > lowerBound && isBST(current->left,current->data,lowerBound) && isBST(current->right, upperBound , current->data );

}

bool isValidBST(Node* current) {

    return isBST(current,maxM, minM) ;

}



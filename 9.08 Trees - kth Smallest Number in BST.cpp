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

int kthSmallest(NODE*,int);

int main(){
    int arr[]={10,21,45,13,87,24,8,3,1,5,19,22};
    NODE* root = NULL;                                   //You can access memory in Heap only using pointers.
                                                         //Also, it is important to declare it NULL, else it will go into the else condition of the insert function and cause runtime error
    for(int i=0;i<12;i++)
        root=insertInBST(arr[i],root);

    cout<<kthSmallest(root,4)<<endl;
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


int kthSmallest(NODE* current, int k) {
        vector<int> res;
        stack<NODE*> st;
        while(!st.empty()||current){
            if(current){
                st.push(current);
                current=current->left;
            }else{
                res.push_back(st.top()->data);
                current=st.top()->right;
                st.pop();
            }
        }

        return res[k-1];
    }



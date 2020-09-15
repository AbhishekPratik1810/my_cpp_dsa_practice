#include<iostream>
using namespace std;

typedef struct NODE{
    int data;
    NODE* left;
    NODE* right;
}NODE;


NODE* insertInBST(int,NODE*);
int getMax(NODE*);
int getMin(NODE*);
int getMaxRecursion(NODE*);
int getMinRecursion(NODE*);

int main(){
    int arr[]={10,21,45,13,87,24,19,22};
    NODE* root = NULL;                                   //You can access memory in Heap only using pointers.
                                                        //Also, it is important to declare it NULL, else it will go into the else condition of the insert function and cause runtime error
    for(int i=0;i<8;i++)
        root=insertInBST(arr[i],root);

    cout<<"Maximum is "<<getMax(root)<<"\t";
    cout<<"Minimum is "<<getMin(root)<<endl;

    cout<<"Maximum via recursion is "<<getMaxRecursion(root)<<"\t";
    cout<<"Minimum via recursion is "<<getMinRecursion(root)<<endl;
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

int getMax(NODE* current){
    while(current->right!=NULL)
        current=current->right;
    return current->data;
}

int getMin(NODE* current){
    while(current->left!=NULL)
        current=current->left;
    return current->data;
}

int getMaxRecursion(NODE* current){
    if(current->right==NULL)
        return current->data;
    return getMaxRecursion(current->right);
}

int getMinRecursion(NODE* current){
    if(current->left==NULL)
        return current->data;
    return getMinRecursion(current->left);
}



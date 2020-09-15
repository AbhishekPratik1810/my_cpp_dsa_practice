#include<iostream>
#include<queue>
using namespace std;

typedef struct NODE{
    int data;
    NODE* left;
    NODE* right;
}NODE;

//Currently I know how to insert in BST only, hence inserted in BST. The level order traversal method though, is in general for any binary tree
NODE* insertInBST(int,NODE*);
void levelOrderTraversal(NODE*);
void badhiyaLOT(NODE*);

int main(){
    int arr[]={10,21,45,13,87,24,19,22};
    NODE* root = NULL;                                   //You can access memory in Heap only using pointers.
                                                        //Also, it is important to declare it NULL, else it will go into the else condition of the insert function and cause runtime error
    for(int i=0;i<8;i++)
        root=insertInBST(arr[i],root);
    //levelOrderTraversal(root);
    badhiyaLOT(root);
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

//EKDUM SASTA AUR GHATIYA TAREEKA? KYUN? KYUNKI ISSE ROOT NODE KABHI PRINT NAHI HOGA, TOH USKE LIYE EK ALAG CONDITION BANANE KI ZAROORAT PAD JAYEGI
void levelOrderTraversal(NODE* current){
    static int i=0;
    if(current==NULL)
        return;
    else{
        if(i==0)
            cout<<current->data<<" ";
        i++;
        if(current->left!=NULL)
            cout<<current->left->data<<" ";
        if(current->right!=NULL)
            cout<<current->right->data<<" ";
        levelOrderTraversal(current->left);
        levelOrderTraversal(current->right);
    }
}
/*
LOGIC:
Store address of not visited nodes in a Queue.
Once you visit a node, print its content, store its left and right nodes in queue(i.e enqueue the children) and pop it from the queue.
A node not in the queue represents that it is now visited
This way, using FIFO of Queue, a node that is discovered first, is visited first
*/
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




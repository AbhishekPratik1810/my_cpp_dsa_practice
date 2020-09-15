#include<iostream>
using namespace std;

typedef struct NODE{
    int data;
    NODE* left;
    NODE* right;
}NODE;


NODE* insertInBST(int,NODE*);
bool searchInBST(int,NODE*);
void menu(NODE*);

int main(){
    int arr[]={10,21,45,13,87,24,19,22};
    NODE* root = NULL;                                   //You can access memory in Heap only using pointers.
                                                        //Also, it is important to declare it NULL, else it will go into the else condition of the insert function and cause runtime error
    for(int i=0;i<8;i++)
        root=insertInBST(arr[i],root);

    menu(root);
}

void menu(NODE* root){
    int opt=0;
    do{
        cout<<"Enter option : ";                                    //0 means quit, else search for item
        cin>>opt;
        if(opt){
            int data;
            cout<<"Enter elt to be searched : ";
            cin>>data;
            cout<<(searchInBST(data,root)?"Found":"Not Found")<<endl;
        }
    }while(opt);
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

bool searchInBST(int data,NODE* currentNode){
    if(currentNode==NULL)
        return false;
    else{
        if(currentNode->data == data)
            return true;
        else if(data<currentNode->data)
            return searchInBST(data,currentNode->left);
        else
            return searchInBST(data,currentNode->right);
    }
}


#include <iostream>


using namespace std;

typedef struct NODE{
    int val=-1;
    NODE* left=NULL;
    NODE* right=NULL;
}NODE;


void insertToBST(int,NODE*);
void printBST(NODE*);
bool searchInBST(int,NODE*);

int main(){
    int arr[] = {15,17,10,20,8,25,12};

    NODE* root = new NODE;

    int opt=0;

    for(int i=0;i<7;i++)
        insertToBST(arr[i],root);


    insertToBST(19,root);
    do{
        cout<<"Enter your option : ";
        cin>>opt;
        int elt;
        if(opt==1){
            cin>>elt;
        }else if(opt==2){
            printBST(root);
            cout<<endl;
        } else if(opt==3){
            cin>>elt;
            cout<<(searchInBST(elt,root)?"Found":"Not Found")<<endl;
        }
    }while(opt!=0);

}

void insertToBST(int element, NODE* root){
    NODE* temp = root;
    NODE* prev = temp;
    if((*root).val==-1)
        (*root).val=element;
    else{
        bool left;
        if(element<=(*temp).val) left=true;
        else left=false;
        while(temp!=NULL){
            if(temp!=NULL && element<=(*temp).val){
                prev=temp;
                temp=(*temp).left;
                left=true;
            }
            else{
                prev=temp;
                temp=(*temp).right;
                left=false;
            }
        }
        NODE* current = new NODE;
        (*current).val=element;
        left?(*prev).left=current : (*prev).right=current;
        cout<<"Inserted "<<element<<(left?" to the left of ":" to the right of ")<<(*prev).val<<endl;

    }
}

void printBST(NODE* root){

    if(root==NULL)
        return;
    else{
        cout<<(*root).val<<" ";
        NODE* temp = root;
        root=(*root).left;
        printBST(root);
        root=(*temp).right;
        printBST(root);
        return;
    }
}

bool searchInBST(int elt,NODE* root){
    while(root!=NULL){
        if(elt==(*root).val)
            return true;
        else if(elt<(*root).val)
            root=(*root).left;
        else
            root=(*root).right;
    }
    return false;
}


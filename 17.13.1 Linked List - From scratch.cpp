#include<iostream>

using namespace std;

struct Node{

    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

};

Node* doTheMagic(Node* head, int k){

    if(!head)
        return NULL;

    Node* prev = NULL, *curr =NULL, *fwd = head;

    int linkCount = 0;

    while(fwd && linkCount<k){

        prev = curr;
        curr = fwd;
        fwd = fwd->next;
        curr->next = prev;
        linkCount++;

    }

    head->next = doTheMagic(fwd,k);

    return curr;

}

void printList(Node* head){

    Node* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}

int main(){

    int nodes, k,val;
    cin>>nodes>>k;

    Node* head=NULL;

    for(int i=0;i<nodes;i++){
        cin>>val;
        Node* naya = new Node(val);
        if(!head)
            head = naya;
        else{
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = naya;
        }
    }

    head = doTheMagic(head,k);

    printList(head);

}

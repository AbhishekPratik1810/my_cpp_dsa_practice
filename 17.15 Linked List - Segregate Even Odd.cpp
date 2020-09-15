//https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list/0

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

Node* evenOdd(Node* head){

    if(!head || !(head->next))
        return head;

    Node* currOdd = NULL, *currEven = NULL, *curr = head,*evenBegin = NULL, *oddBegin=NULL, *prev=NULL;


    while(curr){
        if((curr->data)%2){
            if(!currOdd)
                oddBegin=curr;
            else
                currOdd->next = curr;

            currOdd = curr;
        }else{
            if(!currEven)
                evenBegin = curr;
            else
                currEven->next = curr;
            currEven = curr;
        }
        prev = curr;
        curr=curr->next;
        prev->next = NULL;              //To remove all existing connections
    }

    if(!evenBegin)
        return currOdd;
    else{
        currEven->next = oddBegin;
        return evenBegin;
    }

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

    int t;
    cin>>t;

    while(t--){

        int n,val; cin>>n;

        Node* head = NULL;

        for(int i=0;i<n;i++){

            cin>>val;
            Node* naya = new Node(val);
            if(!head)
                head = naya;
            else{

                Node* curr = head;
                while(curr->next)
                    curr = curr->next;
                curr->next = naya;
            }

        }

        head = evenOdd(head);

        printList(head);

    }

}


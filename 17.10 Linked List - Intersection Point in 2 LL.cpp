//https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(Node* head1, Node* head2)
{
    int totalNodesIn1=0, totalNodesIn2=0;

    Node* curr1 = head1, *curr2 = head2;

    while(curr1){
        totalNodesIn1++;
        curr1=curr1->next;
    }

    while(curr2){
        totalNodesIn2++;
        curr2=curr2->next;
    }
    curr1 = head1, curr2=head2;
    if(totalNodesIn1>totalNodesIn2){
        for(int i=1;i<=(totalNodesIn1-totalNodesIn2);i++)
            curr1 = curr1->next;
    }else{
        for(int i=1;i<=(totalNodesIn2-totalNodesIn1);i++)
            curr2 = curr2->next;
    }

    while(curr1&&curr2){
        if(curr1==curr2)
            return curr1->data;
        curr1=curr1->next;
        curr2=curr2->next;
    }

    return -1;

}

Node* inputList(int size)
{
    if(size==0) return NULL;

    int val;
    cin>> val;

    Node *head = new Node(val);
    Node *tail = head;

    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;

        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends




//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node* iterativeReverseList(struct Node * fwd)
{
    Node* prev = NULL, *curr=NULL;
    while(fwd){
        prev=curr;
        curr=fwd;
        fwd = fwd->next;
        curr->next=prev;
    }

    return curr;
}

struct Node* reverseList(struct Node *curr)
{
    if(!(curr->next))
        return curr;
    Node* newHead = reverseList(curr->next);
    curr->next->next = curr;
    curr->next = NULL;
    return newHead;
}

struct Node* slowerReverseList(struct Node *curr)
{
    if(!(curr->next))
        return curr;
    Node* fwd = reverseList(curr->next);
    Node* temp = fwd;
    int ct = 0;
    while(temp->next)
        temp = temp->next;

    temp->next = curr;
    curr->next = NULL;
    return fwd;
}


void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;

        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;

        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        head = reverseList(head);

        printList(head);
        cout << endl;
    }
    return 0;
}



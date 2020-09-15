//https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* rotate(Node* head, int k)
{
    int totalNodes = 0;

    Node* curr = head;

    while(curr){
        totalNodes++;
        curr = curr->next;
    }

    if(k>=totalNodes)
        return head;

    int currLink=0; curr = head;
    while(currLink<k){
        currLink++;
        curr=curr->next;
    }

    Node* newHead = curr;
    Node* oldHead = head, *prev = head;

    while(curr->next)
        curr = curr->next;

    while(oldHead!=newHead){
        curr->next = oldHead;
        curr = curr->next;
        prev = oldHead;
        oldHead = oldHead->next;
        prev->next = NULL;
    }

    return newHead;

}

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;

        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;

        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }

        cin>> k;

        head = rotate(head,k);
        printList(head);
    }
    return 1;
}

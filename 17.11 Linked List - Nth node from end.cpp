//https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

//One Pass using mid runner technique
int getNthFromLast(Node *head, int n){

    Node* fast=head, *slow = head;

    for(int i=1;i<=n;i++){
        if(fast)
            fast = fast->next;
        else
            return -1;
    }

    while(fast){
        slow=slow->next;
        fast=fast->next;
    }

    return slow->data;



}
int twoPassgetNthFromLast(Node *head, int n)
{
       int count=0;
       Node* curr = head;

       while(curr){
           count++;
           curr=curr->next;
       }

       if(n>count)
        return -1;

       curr = head;
       for(int i=1;i<=(count-n);i++)
        curr=curr->next;

        return curr->data;

}




/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}





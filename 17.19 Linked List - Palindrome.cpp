//https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* reverse(Node* head){
    Node* prev,*curr,*fwd=head;

    while(fwd){
        prev=curr;
        curr=fwd;
        fwd = fwd->next;
        curr->next = prev;
    }

    return curr;

}

bool isPalindrome(Node *head)
{
    if(!head || !(head->next))
        return 1;
    Node* slow=head, *fast = head, *prev;

    while(fast && fast->next){
        fast = fast->next->next;
        if(!fast)
            break;

        prev = slow;
        slow = slow->next;
    }

    Node* rightList = reverse(slow->next);
    if(fast)
        slow = prev;

    while(head!=slow->next){

        if(rightList->data != head->data)
            return 0;
        rightList = rightList->next;
        head = head->next;

    }
    return 1;

}

int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {

        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}





//https://practice.geeksforgeeks.org/problems/rearrange-a-linked-list/1
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
Node *rearrangeEvenOdd(Node *head)
{
    if(!head || !(head->next))
        return head;
   Node* odd = head;
   Node* even = head->next, *evenBegin = head->next;

   while(even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        if(odd->next)
        even = even->next;          //We don't want even to ever be NULL, else even->next will give segmentation fault
   }

   odd->next = evenBegin;

   return head;
}
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {
                head = temp = new Node(l);

            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }

        head = rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}


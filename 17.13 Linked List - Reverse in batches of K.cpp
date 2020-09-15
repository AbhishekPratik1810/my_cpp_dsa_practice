//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

};


pair<node*,node*> rev(node* head, int count){

    node* prev = NULL, *curr = NULL, *fwd = head;

    int ctr = 0;
    while(ctr<count && fwd){
        prev = curr;
        curr = fwd;
        fwd = fwd->next;
        curr->next = prev;
        ctr++;
    }

    return make_pair(curr,fwd);



}

node* reverseList(node* A, int B) {

    if(!A)
        return NULL;

    pair<node*,node*> p = rev(A,B);

    node* head  = p.first;
    node* newStart = p.second;
    node* ending = A;

    ending->next = reverseList(newStart,B);

    return head;


}


//WOW.
struct node *reverse (struct node *head, int k)
{
    if(!head)
        return NULL;
    node* prev=NULL, *curr = NULL, *fwd = head;
    int linkCount=0;

    while(fwd && linkCount<k){
        prev=curr;
        curr=fwd;
        fwd = fwd->next;
        curr->next = prev;
        linkCount++;
    }

    head->next = reverse(fwd,k);

    return curr;

}



struct node *constantSpaceReverse (struct node *head, int k)
{

    if(!head)
        return head;

    node* prevRevLast, *currFwdLast = NULL;

    node* prev=NULL,*fwd = head;

    int linkCount=0;

    while(fwd && linkCount<k){
        prev = currFwdLast;
        currFwdLast = fwd;
        fwd = fwd->next;
        currFwdLast->next = prev;
        linkCount++;
    }


    prevRevLast = head;
    head = currFwdLast;

    while(fwd){

        linkCount=0;
        node* newHead = fwd;
        prev=NULL,currFwdLast=NULL;

        while(fwd && linkCount<k){
            prev = currFwdLast;
            currFwdLast = fwd;
            fwd = fwd->next;
            currFwdLast->next = prev;
            linkCount++;
        }

        prevRevLast->next = currFwdLast;
        prevRevLast = newHead;

    }

    return head;

}

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;

    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;

        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin>>k;

        head = reverse(head, k);
        printList(head);
    }

    return(0);
}



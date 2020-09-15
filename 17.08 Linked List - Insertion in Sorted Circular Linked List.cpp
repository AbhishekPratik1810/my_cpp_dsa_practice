//https://practice.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1
#include<bits/stdc++.h>

struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }

};

Node *sortedInsert(Node* head, int x)
{
    if(!head)
        return head = new Node(x);
    if(head->data>x){
        Node* curr = head;
        while(curr->next!=head)
            curr = curr->next;
        Node* naya = new Node(x);
        naya->next = head;
        curr->next = naya;
        return naya;
    }else{

        Node* prev = head;
        Node* curr = head->next;

        while(curr!=head){
            if(curr->data>x)
                break;
            prev = curr;
            curr = curr->next;
        }

        Node* naya = new Node(x);
        naya->next = prev->next;
        prev->next = naya;

        return head;
    }
}
void printList(struct Node *start)
{
  struct Node *temp;

  if(start != NULL)
  {
    temp = start;
    do { printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != start);
    printf("\n");
  }
}
/* Driver program to test above functions */
int main()
{
int t,n,x;
scanf("%d",&t);
int arr;
  while(t--){
  scanf("%d",&n);
  int list_size, i;

  /* start with empty linked list */
  struct Node *start = NULL;
  struct Node *temp,*r;


    /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
    if(n>0){
      scanf("%d",&arr);

    temp = new Node(arr);
    start=temp;
    r=start;
    }
    for (i = 0; i<n-1; i++)
    {
        scanf("%d",&arr);
        temp = new Node(arr);
        r->next=temp;
        r=r->next;
    }

    if(n>0)
    temp->next=start;

    scanf("%d",&x);
    start = sortedInsert(start,x);
    printList(start);
    r=start;
    while(r!=start->next)
    {

      temp=start;
      start=start->next;
      free(temp);
    }
    free(start);
}
  return 0;
}


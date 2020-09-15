// { Driver Code Starts
#include<iostream>
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

Node* inPlaceSortedMerge(Node* A, Node* B)
{
    if(!A)
        return B;
    if(!B)
        return A;
    if(A->data < B->data){
        A->next = sortedMerge(A->next, B);
        return A;
    }
    else{
        B->next = sortedMerge(A,B->next);
        return B;
    }


}
//This is also O(1) as only one unit of extra memory for head is created
Node* sortedMerge(Node* A, Node* B)
{
    Node* head = new Node(-1);                              //The Errichto Way!
    Node* temp = head;

    while(A && B){
        if(A->data<B->data){
            temp->next = A;
            temp = temp->next;
            A = A->next;
        }else{
            temp->next = B;
            temp = temp->next;
            B = B->next;
        }
    }

    if(A) temp->next = A;
    if(B) temp->next = B;

    return head->next;

}
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}



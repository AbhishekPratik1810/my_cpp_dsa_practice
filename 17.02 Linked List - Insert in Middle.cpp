//https://practice.geeksforgeeks.org/problems/insert-in-middle-of-linked-list/1
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// function to display the linked list
void display(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout<<endl;
}

Node* insertInMiddle(Node* head, int x)
{

    if(!head)
        return head =  new Node(x);
	int count=0;
	Node* temp = head;
	while(temp){
	    count++;
	    temp=temp->next;
	}

	temp = head;
	count= (count+1)/2;
	for(int i=1;i<count;i++){
	    temp = temp->next;
	}

	Node* naya = new Node(x);
	naya->next = temp->next;
	temp->next = naya;

	return head;



}

int main()
{
    int T, n, x;
    cin>>T;
    while(T--)
    {
        cin>> n >> x;

        struct Node *head = new Node(x);
        struct Node *tail = head;

        for (int i=0; i<n-1; i++)
        {
            cin>>x;
            tail->next = new Node(x);
            tail = tail->next;
        }

        cin>> x;
        head = insertInMiddle(head, x);
        display(head);
    }
    return 0;
}

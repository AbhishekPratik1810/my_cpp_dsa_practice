//https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1
#include <bits/stdc++.h>
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

Node *sortedInsert(struct Node* head, int data) {
    if(!head)
        return head = new Node(data);
    if(head->data>data){
        Node* naya = new Node(data);
        naya->next = head;
        head = naya;
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;

    while(curr){

        if(curr->data>data)
            break;


        prev = curr;
        curr=curr->next;
    }

    Node* naya = new Node(data);
    naya->next = prev->next;
    prev->next = naya;
    return head;


}

void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data <<" ";
		node = node->next;
	}
	cout<<"\n";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;

		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}

		int k;
		cin>>k;

		head = sortedInsert(head,k);
		printList(head);
	}
	return 0;
}


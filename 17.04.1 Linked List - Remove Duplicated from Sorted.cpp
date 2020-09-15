// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
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


Node *removeDuplicates(Node *root)
{
    if(!root)
        return root;
    Node* prev = root;
    Node* curr = root->next;
    while(curr){
        if(curr->data==prev->data){
            prev->next = curr->next;
            Node* toDelete = curr;
            curr = curr->next;
            delete toDelete;
            toDelete = NULL;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }

    return root;

}
void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}


int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}

		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}

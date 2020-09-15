//https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
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

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}

Node * removeDuplicates( Node *head)
{
    unordered_map<int,bool> vis;

    Node* temp = head;
    Node* prev = NULL;
    while(temp){

        if(!vis[temp->data]){
            vis[temp->data]=1;
            prev = temp;
            temp=temp->next;
        }else{
            Node* toDelete = temp;
            prev->next = temp->next;
            temp=temp->next;
            delete toDelete;
            toDelete=NULL;
        }
    }

    return head;

}

int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

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


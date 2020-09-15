//https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

bool floydCycleDetection(Node* head)
{
    Node* first =  head,*second = head;

    while(first&&second){
        first = first->next;
        second = second->next;
        if(second) second = second->next;
        if(first && second && first==second)
            return 1;
    }
    return 0;

}

bool detectLoop(Node* head)
{
    unordered_map<Node*,bool> vis;

    while(head){
        if(!vis[head]){
            vis[head]=1;
            head = head->next;
        }else{
            return 1;
        }
    }

    return 0;
}

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;

    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;

        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);

        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin>> pos;
        loopHere(head,tail,pos);

        if( detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}



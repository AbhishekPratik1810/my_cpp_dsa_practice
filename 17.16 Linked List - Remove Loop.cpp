//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
//https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781/Concise-O(n)-solution-by-using-C%2B%2B-with-Detailed-Alogrithm-Description
/*
For anyone confused why slow and fast are equidistant (travelling forward) from the meeting point to the entry point

Let's further break down C, given the following:
L2 = distance from entry to meeting point
L3 = distance from meeting point to entry (forward in loop)
then we have C = L2 + L3

We already have L1 = (n - 1) C + (C - L2) from ngcl's excellent explanation.

(n - 1)C
This is n-1 traversals of the loop distance C

C - L2
Substitute for C: (L2 + L3) - L2 => L3

Finally we get: L1 = (n - 1)C + L3.

Therefore, distance from head to entry is the same as the forward distance (following the loop) from meeting point to entry + n - 1 loop traversals

*/

#include <iostream>
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

void removeLoop(Node* head)
{
    if(!head)
        return;

    Node* slow=head, *fast = head, *beg = head, *prev = head;

    while(fast && fast->next){+
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
        if(slow==fast){

            while(slow!=beg){                   //slow == beg at the entry point
                prev = slow;
                slow=slow->next;
                beg = beg->next;
            }

            prev->next = NULL;
            return;
        }
    }


}

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;

    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;

    Node* fast = head->next;
    Node* slow = head;

    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }

    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
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

        removeLoop(head);

        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
// } Driver Code Ends




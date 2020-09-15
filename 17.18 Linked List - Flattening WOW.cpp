//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1/
//O(N*M) | O(1)
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;

	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}

};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;

			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){

				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


Node* merge(Node* A, Node* B){
    if(!A)
        return B;
    if(!B)
        return A;
    if(A->data<B->data){
        A->bottom = merge(A->bottom,B);
        return A;
    }else{
        B->bottom = merge(A,B->bottom);
        return B;
    }
}




Node* middle(Node* curr){

    Node* fast = curr, *slow = curr;
    while(fast && fast->bottom){
        fast = fast->bottom->bottom;
        if(!fast)
            break;
        slow = slow->bottom;
    }
    return slow;

}





Node* mergeSort(Node* curr){

    if(!curr || !(curr->bottom))
        return curr;

    Node* mid = middle(curr);
    Node* left = curr;
    Node* right = mid->bottom;
    mid->bottom= NULL;
    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left,right);

}


Node *flatten(Node *root)
{
    Node* curr = root, *fwd=NULL;
    while(curr){
        mergeSort(curr);
        curr = curr->next;
    }
    curr = root;
    while(curr->next){
        fwd = curr->next;
        curr->next=NULL;
        curr = fwd;
        root = merge(root,fwd);
    }

    return root;


}


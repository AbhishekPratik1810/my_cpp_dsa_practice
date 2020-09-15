//https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* merge(Node* left, Node* right){

    if(!left)
        return right;
    if(!right)
        return left;
    if(left->data<right->data){
        left->next = merge(left->next,right);
        return left;
    }
    else{
        right->next = merge(left,right->next);
        return right;
    }


}


Node* middle(Node* head){

    Node* fast = head, *slow = head;

    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;

}

Node* twoPassMiddle(Node* head){

    int count=0;
    Node* curr = head;
    while(curr){
        curr=curr->next;
        count++;
    }
    count = (count-1)/2;
    curr = head;
    for(int i=1;i<=count;i++)
        curr = curr->next;

    return curr;
}


Node* mergeSort(Node* head) {

    if(!head || !(head->next))
        return head;

    Node* mid = middle(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next =NULL;                //Break the link about middle
    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left,right);       //Restore the connection



}


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends

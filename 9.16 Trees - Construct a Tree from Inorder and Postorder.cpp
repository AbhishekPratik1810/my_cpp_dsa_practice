//https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


map<int,int> pos;

int getPostStart(int inStart, int inEnd, int postEnd){
    return postEnd - (inEnd-inStart);
}

Node* buildRec(int in[], int post[], int inStart, int inEnd, int postStart, int postEnd){

    if(inStart>inEnd)
        return NULL;

    Node* curr = new Node(post[postEnd]);
    int inPos = pos[post[postEnd]];
    int rightPostStart = getPostStart(inPos+1,inEnd,postEnd-1);

    curr->right = buildRec(in,post,inPos+1,inEnd,rightPostStart,postEnd-1);         //CAN EVEN SWITCH THE 2 AND BUILD LEFT PART FIRST!
    curr->left = buildRec(in,post,inStart,inPos-1,postStart,rightPostStart-1);

    return curr;

}


Node *buildTree(int in[], int post[], int n) {

    pos.clear();

    for(int i=0;i<n;i++)
        pos[in[i]] = i;

    return buildRec(in,post,0,n-1,0,n-1);

}


void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}




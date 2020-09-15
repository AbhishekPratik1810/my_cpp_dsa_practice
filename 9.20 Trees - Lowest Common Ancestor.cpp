//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node * lca(Node* root,int n1,int n2);
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        cout<<lca(root,a,b)->data<<endl;
    }
    return 0;
}

Node* lca(Node* root ,int n1 ,int n2 )
{

   if(!root) return NULL;

   if(root->data == n1 || root->data == n2)
    return root;

   Node* leftValue = lca(root->left,n1,n2);
   Node* rightValue = lca(root->right,n1,n2);

   if(leftValue && rightValue)
    return root;

   if(leftValue) return leftValue;
   if(rightValue) return rightValue;

   return NULL;

}


//M2

Node* ans;

bool isPresent(Node* curr, int n1, int n2){

    if(!curr) return 0;

    if(curr->data == n1 || curr->data == n2){
        ans = curr;
        return 1;
    }

    bool foundInLeft = isPresent(curr->left,n1,n2);
    bool foundInRight = isPresent(curr->right,n1,n2);

    if(foundInLeft && foundInRight){
        ans = curr;
        return 1;
    }

    return (foundInLeft||foundInRight) ;

}

Node* lca2(Node* root ,int n1 ,int n2 )
{

   ans=NULL;

   if(isPresent(root,n1,n2))
        return ans;
   else
        return NULL;

}

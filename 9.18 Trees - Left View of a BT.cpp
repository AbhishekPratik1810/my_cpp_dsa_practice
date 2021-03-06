//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1/

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

void leftView(struct Node *root);

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


int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        leftView(root);
        cout << endl;
    }
    return 0;
}


void dfs(Node* root, int currLevel, vector<bool> &vis){

    if(!root) return;
    if(!vis[currLevel]) {
        cout<<root->data<<" ";
        vis[currLevel]=1;
    }
    dfs(root->left,currLevel+1,vis);
    dfs(root->right,currLevel+1,vis);

}

void spaceEfficientDFS(Node* root, int currLevel, int &maxLevel){
    if(!root) return;
    if(maxLevel<currLevel){
        cout<<root->data<<" ";
        maxLevel=currLevel;
    }
    spaceEfficientDFS(root->left,currLevel+1,maxLevel);
    spaceEfficientDFS(root->right,currLevel+1,maxLevel);
}

void leftView(Node *root)
{

   //M1
   vector<bool> vis(1000,0);
   dfs(root,0,vis);

   //M2
   int maxLevel = -1;
   spaceEfficientDFS(root,0,maxLevel);

   //M3
   if(!root) return;

   queue<Node*> q;
   cout<<root->data<<" ";
   q.push(root);
   q.push(NULL);

   bool ok=0;

   while(!q.empty()){
       root = q.front();
       q.pop();
       if(!root){
           ok=1;
           if(!q.empty())
            q.push(NULL);
       }else{
           if(ok)
            cout<<root->data<<" ";
           ok=0;
           if(root->left) q.push(root->left);
           if(root->right) q.push(root->right);

       }
   }

}

//https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

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


 // } Driver Code Ends


/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class solver
{
private:

public:

    map<int,vector<int>> adjList;
    vector<int> res;

    void buildGraph(Node* root){

        if(root->left){
            adjList[root->data].push_back((root->left)->data);
            adjList[(root->left)->data].push_back(root->data);
            buildGraph(root->left);
        }
        if(root->right){
            adjList[root->data].push_back(root->right->data);
            adjList[(root->right)->data].push_back(root->data);
            buildGraph(root->right);
        }


    }

    void dfs(int src,int k,int curr,map<int,bool> &vis){

        vis[src]=1;

        if(curr==k)
            res.push_back(src);

        for(auto i : adjList[src]){
            if(!vis[i]){
                dfs(i,k,curr+1,vis);
            }
        }
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        //M1 Create the graph
        res.clear();
        adjList.clear();

        buildGraph(root);

        map<int,bool> vis;
        dfs(target,k,0,vis);

        sort(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();

    solver x = solver();

    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);

        int target, k;
        cin>> target >> k;
        getchar();

        vector <int> res = x.KDistanceNodes(head, target, k);

        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends

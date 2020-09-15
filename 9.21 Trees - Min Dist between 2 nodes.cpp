//https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1/

/*
    M1 : Using LCA
    M2 : Find path from root to a, path from root to b
         ans = p1+p2 - 2*(path common to p1 and p2)
*/

#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* findLCA(Node* root, int a, int b){
    if(!root) return NULL;
    if(root->data == a || root->data == b)
        return root;
    Node* foundInLeft = findLCA(root->left,a,b);
    Node* foundInRight = findLCA(root->right,a,b);

    if(foundInLeft && foundInRight)
        return root;

    if(foundInLeft) return foundInLeft;
    return foundInRight;

}

int d1,d2;

void dfs(Node* root,int a,int b,int cDis){
    if(!root) return;
    if(root->data == a)
        d1 = cDis;
    if(root->data == b)
        d2 = cDis;
    dfs(root->left,a,b,cDis+1);
    dfs(root->right,a,b,cDis+1);
}

int findDist(Node* root, int a, int b) {
    //Find LCA, then DFS from LCA to both nodes

    d1=0,d2=0;

    Node* lca = findLCA(root,a,b);

    dfs(lca,a,b,0);


    return d1+d2;
}


// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        cout << findDist(root, n1, n2) << "\n";
    }
    return 0;
}// } Driver Code Ends

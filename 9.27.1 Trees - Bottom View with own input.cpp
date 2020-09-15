#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    int height;
    Node* right;
    Node* left;
    Node(int val){
        this->data = val;
        this->height = 0;
        right = NULL;
        left = NULL;
    }
};


Node* buildTree(vector<int> input)
{

    if(input.size() == 0)
        return NULL;

    Node* root = new Node(input[0]);

    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1,leftChild,rightChild;
    while(!queue.empty() && i < input.size()) {

        Node* currNode = queue.front();
        queue.pop();

        leftChild = input[i];

        // If the left child is not null
        if(leftChild != -1) {

            currNode->left = new Node(leftChild);
            queue.push(currNode->left);

        }

        // For the right child
        i++;
        if(i >= input.size())
            break;
        rightChild = input[i];

        // If the right child is not null
        if(rightChild != -1) {

            currNode->right = new Node(rightChild);
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


void dfs(Node* root,map<int,Node*> &lowestNodes, int cDis, int cHeight){

    if(!root) return;

    root->height = cHeight;

    if(lowestNodes.find(cDis)==lowestNodes.end() || (lowestNodes[cDis]->height)<=cHeight)
        lowestNodes[cDis] = root;

    dfs(root->left,lowestNodes,cDis-1,cHeight+1);
    dfs(root->right,lowestNodes,cDis+1,cHeight+1);

}

int main(){


    string str;
    getline(cin,str);

    vector<string> ip;

    vector<int> arr;

    istringstream iss(str);
    for(string str; iss >> str; )
        arr.push_back(stoi(str));

    Node* root = buildTree(arr);


    map<int,Node*> lowestNodes;            //maps horizontal distance to the lowest node in tree.

    dfs(root,lowestNodes,0,0);

    for(auto p : lowestNodes)
        cout<<p.second->data<<" ";
    cout<<endl;

}

/*
    Sample Input
    1 2 3 -1 4 -1 5 -1 -1 -1 6 -1 7 -1 8 -1 -1

    Sample Output
    2 4 3 5 6 7 8
*/

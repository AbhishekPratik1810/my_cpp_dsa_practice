#include<iostream>
#include<vector>
#include<cstring>
#include<sstream>
#include<queue>
#include<map>
using namespace std;

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right=NULL;
    }

};

Node* buildTree(vector<int> arr){

    queue<Node*> q;
    Node* root = new Node(arr[0]);          //Get root node by default
    Node* curr;
    q.push(root);

    int lastIdx = arr.size()-1;
    int currIdx = 1;                        //Start from second index

    while(currIdx<=lastIdx && !q.empty()){

        curr = q.front();
        q.pop();

        if(arr[currIdx]!=-1){
            curr->left = new Node(arr[currIdx]);
            q.push(curr->left);
        }

        currIdx++;

        if(currIdx>lastIdx)
            break;

        if(arr[currIdx]!=-1){
            curr->right = new Node(arr[currIdx]);
            q.push(curr->right);
        }

        currIdx++;

    }

    return root;

}

map<int,int> levels;


void topView(Node* root, int currLevel){

    if(!root) return;
    if(!levels[currLevel])
        levels[currLevel] = root->data;
    topView(root->left,currLevel-1);
    topView(root->right,currLevel+1);

}


int main(){

    string s;
    getline(cin,s);

    vector<int> arr;

    istringstream iss(s);
    for(string val; iss >> val; )
        arr.push_back(stoi(val));

    Node* root = buildTree(arr);

    topView(root,0);

    for(auto p : levels)
        cout<<p.second<<" ";
    cout<<endl;

}

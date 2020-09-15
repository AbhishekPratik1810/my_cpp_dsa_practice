//https://practice.geeksforgeeks.org/problems/largest-bst/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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

struct Info{

    bool isBST   = 1;
    int minElement = INT_MAX;                 //            root->data < rightSubtree.minElement            Hence by default taken as INT_MAX
    int maxElement = INT_MIN;                //             leftSubtree.maxElement < root->data             Hence by default taken as INT_MIN
    int maxSizeBST = 0;

    Info(int maxSize){
        maxSizeBST = maxSize;
    }

    Info(int minVal, int maxVal){
        minElement = minVal;
        maxElement = maxVal;
        maxSizeBST = 1;
    }

};

Info* help(Node* root){

    if(!root) return new Info(0);

    if((!root->left) && (!root->right)) return new Info(root->data,root->data);

    Info* leftSubtree = help(root->left);
    Info* rightSubtree = help(root->right);

    Info* answer = new Info(0);

    if(leftSubtree->isBST && rightSubtree->isBST &&   leftSubtree->maxElement < root->data  && root->data < rightSubtree->minElement){
        answer->maxSizeBST = leftSubtree->maxSizeBST + rightSubtree->maxSizeBST + 1;
        answer->minElement = min(leftSubtree->minElement,root->data);                   //root->data if leftSubtreeIsLeaf, else leftSubtree.minElement
        answer->maxElement = max(root->data,rightSubtree->maxElement);                  //root->data if rightSubtreeIsLeaf, else rightSubtree.maxElement

    }else{
        answer->isBST = 0;
        answer->maxSizeBST = max(leftSubtree->maxSizeBST,rightSubtree->maxSizeBST);
    }

    return answer;


}

int largestBst(Node *root)
{
	return help(root)->maxSizeBST;
}

/*
class Info{
    public :
        bool isBST ;
        int minElement;
        int maxElement;
        int maxSizeBST;

    Info(){
        isBST = 1;
        minElement = INT_MAX;
        maxElement = INT_MIN;
        maxSizeBST = 0;
    }

    Info(int minVal, int maxVal){
        isBST = 1;
        minElement = minVal;
        maxElement = maxVal;
        maxSizeBST = 1;
    }

};

Info help(Node* root){

    if(!root) return Info();
    if((!root->right) && (!root->left)) return Info(root->data,root->data);

    Info leftSubtree = help(root->left);
    Info rightSubtree = help(root->right);

    Info ans ;                              //Note by doing this, in C++, the object is automatically created I guess

    if(leftSubtree.isBST && rightSubtree.isBST &&  leftSubtree.maxElement < root->data && root->data < rightSubtree.minElement){

        ans.maxSizeBST = leftSubtree.maxSizeBST + rightSubtree.maxSizeBST + 1;
        ans.minElement = min(leftSubtree.minElement,root->data);                //root->data if leftSubtreeIsLeaf, else leftSubtree.minElement
        ans.maxElement = max(rightSubtree.maxElement,root->data);               //root->data if rightSubtreeIsLeaf, else rightSubtree.maxElement

    }else{
        ans.isBST = 0;
        ans.maxSizeBST = max(leftSubtree.maxSizeBST,rightSubtree.maxSizeBST);
    }

    return ans;

}

int usingClasses(Node *root)
{
	return help(root).maxSizeBST;
}
*/





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
   Node* root = new Node(stoi(ip[0]));

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
           currNode->left = new Node(stoi(currVal));

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
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s;
       getline(cin, s);
       Node* root1 = buildTree(s);

       //getline(cin, s);
      // int k = stoi(s);
       // getline(cin, s);

       cout << largestBst(root1);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends



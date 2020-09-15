#include<iostream>
#include<queue>
#include<stack>
using namespace std;

typedef struct NODE{
    int data;
    NODE* left;
    NODE* right;
}NODE;

//Currently I know how to insert in BST only, hence inserted in BST. The depth first traversal method though, is in general for any binary tree
NODE* insertInBST(int,NODE*);

void preOrder(NODE*);
void preOrderItr(NODE*);
void inOrder(NODE*);
void inOrderItr(NODE*);
void postOrder(NODE*);
void postOrderItr(NODE*);

int main(){
    int arr[]={10,21,45,13,87,24,8,3,1,5,19,22};
    NODE* root = NULL;                                   //You can access memory in Heap only using pointers.
                                                        //Also, it is important to declare it NULL, else it will go into the else condition of the insert function and cause runtime error
    for(int i=0;i<12;i++)
        root=insertInBST(arr[i],root);

    preOrder(root); cout<<endl;
    preOrderItr(root);
    inOrder(root); cout<<endl;
    inOrderItr(root);
    postOrder(root);cout<<endl;
    postOrderItr(root);
}


NODE* insertInBST(int data, NODE* currentNode){
    if(currentNode==NULL){
        NODE* node = new NODE;
        node->data=data; node->left=node->right=NULL;
        currentNode=node;
    }else{
        if(data<=currentNode->data)
            currentNode->left = insertInBST(data,currentNode->left);
        else
            currentNode->right = insertInBST(data,currentNode->right);
    }
    return currentNode;
}

void preOrder(NODE* current){
    if(current==NULL)
        return;
    else{
        cout<<current->data<<" ";
        preOrder(current->left);
        preOrder(current->right);
    }
}

void preOrderItr(NODE* current){
    if(current==NULL)
        return;
    else{
        stack<NODE*> st;
        st.push(current);
        while(!st.empty()){
            current=st.top();
            cout<<current->data<<" ";
            st.pop();
            if(current->right!=NULL) st.push(current->right);                           //FIRST IN, LAST OUT
            if(current->left!=NULL) st.push(current->left);
        }
        cout<<endl;
    }
}

void inOrder(NODE* current){
    if(current==NULL)
        return;
    else{
        inOrder(current->left);
        cout<<current->data<<" ";
        inOrder(current->right);
    }
}

void inOrderItr(NODE* current){
    if(current==NULL)
        return;
    else{
        stack<NODE*> st;
        while(!st.empty() || current){
            if(current){
                st.push(current);
                current=current->left;
            }else{
                cout<<st.top()->data<<" ";
                current=(st.top())->right;
                st.pop();
            }
        }
        cout<<endl;
    }
}

vector<int> inOrderItrWithMap(Node* curr){

    vector<int> res;

    if(curr){

        stack<Node*> st;
        st.push(curr);

        unordered_map<Node*,bool> vis;

        while(!st.empty()){

            curr = st.top();

            if(curr->left && !vis[curr->left])
                st.push(curr->left);
            else{

                res.push_back(curr->data);
                st.pop();
                vis[curr]=1;
                if(curr->right)
                    st.push(curr->right);


            }

        }

    }

    return res;

}

void postOrder(NODE* current){
    if(current==NULL)
        return;
    else{
        postOrder(current->left);
        postOrder(current->right);
        cout<<current->data<<" ";
    }
}

//You are basically traversing in Root,Right,Left fashion, storing in a stack, and then printing from the top of the stack, which now becomes Left,Right,Root i.e opp of PreOrder
void postOrderItr(NODE* current){
    if(current==NULL)
        return;
    else{
        stack<NODE*> st; stack<int> vis;
        st.push(current);
        while(!st.empty()){
            current=st.top();
            vis.push(current->data);
            st.pop();
            if(current->left) st.push(current->left);
            if(current->right) st.push(current->right);
        }
        while(!vis.empty()){
            cout<<vis.top()<<" ";
            vis.pop();
        }
        cout<<endl;
    }

}

vector<int> sameTemplatePre(NODE* current,vector<int> res){

    if(current==NULL)
        return res;

    stack<NODE*> st;

    while(!st.empty()||current){

        if(current){

           res.push_back(current->data);
           st.push(current);
           current=current->left;

        }else{

            current=st.top(); st.pop();
            current=current->right;

        }
    }
    return res;
}

vector<int> sameTemplateIn(NODE* current,vector<int> res){
    if(current==NULL)
        return res;

    stack<NODE*> st;

    while(!st.empty()||current){
        if(current){

            st.push(current);
            current=current->left;

        }else{

            res.push_back(st.top()->data);
            current = st.top()->right;
            st.pop();

        }
    }

    return res;
}

vector<int> sameTemplatePost(NODE* current,vector<int> res){
    if(current==NULL)
        return res;
    stack<NODE*> st;
    while(!st.empty() || current){
        if(current){
            st.push(current);
            res.push_back(current->data);
            current=current->right;
        }else{
            current=st.top();st.pop();
            current=current->left;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}


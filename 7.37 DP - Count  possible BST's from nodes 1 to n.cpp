//https://practice.geeksforgeeks.org/problems/unique-bsts/0
/*
    Catch here is that it doesn't matter if nodes are numbered from 1 to n
    They can be numbered from k to n also, where k<=n
    However, there must be 2 conditions
    i) There must be no gap between the nodes i.e the sequence should be k,k+1,k+2...n
    ii) The nodes must be strictly increasing

    Hence suppose f(4) gives number of BST from 1 to 4, => g(11) which denotes number of BST from 7 to 10 will be equal to f(4)  (Note 7-10 => 4 nodes)

    Pick a node from 1 to n which has to be made the root. Let it be 'i'.
    f(i-1) gives BST in Left Subtree
    f(n-i) gives BST in Right Subtree  Again note, number of nodes in Right subtree will be from i+1,i+2,i+3...n = Nodes from 1..n - 1..i = n-i
    => f(i-1)*f(n-i) gives Total BST Combinations for ith root node
    This 'i' ranges from 1 to n
    => f(n) =   sum  (f(i-1)*f(n-i))
              1<=i<=n

    Also note, f(0) = 1 (As we are multiplying f(i-1)*f(n-i) if any of the left subtree is empty => that can be done in 1 ways.
    If it is made 0 => for every empty subtree on right/left, the count = 0 which is incorrect

    f(n) is also given by Catalan Number on simplification = 2nCn/n+1
*/

#include<iostream>
using namespace std;

int memo[11];

long long bstCount(int n){
    if(n==0) return 1;
    if(memo[n]) return memo[n];
    long long totalCount=0,leftSubtreeCount=0,rightSubtreeCount=0;
    for(int i=1;i<=n;i++){
        leftSubtreeCount  = bstCount(i-1);
        rightSubtreeCount = bstCount(n-i);
        totalCount+=leftSubtreeCount*rightSubtreeCount;
    }
    return memo[n] = totalCount;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i=0;i<11;i++) memo[i]=0;
        cout<<bstCount(n)<<endl;
    }
}

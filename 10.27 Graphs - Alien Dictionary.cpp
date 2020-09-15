//https://practice.geeksforgeeks.org/problems/alien-dictionary/1
// { Driver Code Starts
// Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include <bits/stdc++.h>

using namespace std;

string findOrder(string[], int, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        string ss = findOrder(s, n, k);

        cout<<ss<<endl;
    }
    return 0;
}



vector<char> ans;

void dfs(char src, bool vis[], map<char,vector<char>> adjList){
    vis[src-97]=1;
    for(auto i: adjList[src]){
        if(!vis[i-97])
            dfs(i,vis,adjList);
    }
    ans.push_back(src);
}

string findOrder(string dict[], int N, int k) {
    // Your code here

    map<char,vector<char>> adjList;
    ans.clear();

    bool vis[27];

    string s1,s2;
    int l1,l2;
    for(int i=0;i<N-1;i++){
        s1 = dict[i], s2 = dict[i+1];
        l1 = s1.size(), l2 = s2.size();
        for(int i=0;i<min(l1,l2);i++){
            if(s1[i]!=s2[i]){
                adjList[s1[i]].push_back(s2[i]);
                break;
            }
        }
    }

    for(int i=0;i<k;i++)
        vis[i]=0;

    for(int i=0;i<k;i++){
        if(!vis[i]){
            dfs(i+97,vis,adjList);
        }
    }

    reverse(ans.begin(),ans.end());

    return string(ans.begin(),ans.end());

}

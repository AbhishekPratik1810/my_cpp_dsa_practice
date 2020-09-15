//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}

vector <int> bfs(vector<int> g[], int N) {

    vector<int> ex;                             //Here I have used, ex: meaning all the adjacent vertices of an elt in ex have been explored completely
    queue<int> vis;                             //Here I have used vis: meaning all the adjacent vertices of an elt in vis is yet to be explored
    map<int,int> mp;
    vis.push(0);
    while(!vis.empty()){
        int a=vis.front();
        ex.push_back(a);
        for(int i=0;i<g[a].size();i++){
            if(!mp[g[a][i]]){
                vis.push(g[a][i]);
                mp[g[a][i]]++;
            }
        }
        vis.pop();
    }
    return ex;
}

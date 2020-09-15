#include<bits/stdc++.h>
using namespace std;


void dfs(int src,vector<int> adj[],vector<int> &order, vector<bool> &vis){
    vis[src]=1;
    for(auto e : adj[src]){
        if(!vis[e])
            dfs(e,adj,order,vis);
    }
    order.push_back(src);


}

void dfsRev(int src,vector<vector<int>> &adjRev,int color, vector<bool> &vis, vector<int> &comp){

        vis[src]=1;
        comp[src]=color;
        for(auto e : adjRev[src]){
            if(!vis[e])
                dfsRev(e,adjRev,color,vis,comp);
        }


}


int kosaraju(int V, vector<int> adj[]){

    vector<vector<int>> adjRev(V);

    for(int i=0;i<V;i++){
        for(auto e : adj[i])
            adjRev[e].push_back(i);
    }

    vector<int> order;
    vector<int> comp(V);
    vector<bool> vis(V,0);

    for(int i=0;i<V;i++){
        if(!vis[i])
            dfs(i,adj,order,vis);
    }
    for(int i=0;i<V;i++) vis[i]=0;

    int color = 1;
    for(int i=V-1;i>=0;i--){
        if(!vis[order[i]]){
            dfsRev(order[i],adjRev,color,vis,comp);
            color++;
        }
    }

    set<int> unique;
    for(int i=0;i<V;i++)
        unique.insert(comp[i]);
    return unique.size();
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}

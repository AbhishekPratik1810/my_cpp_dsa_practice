#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//For dfs
bool* vis;
vector<int> res;
//For Kahn
queue<int> q;
int* indegree;

//Note a correct top sort will mean that all arrows in the graph will go from left to right

//No need to reverse the answer
void kahnTopSort(vector<vector<int>> adj,int current){
    for(auto i:adj[current]){
        indegree[i]--;
        if(!indegree[i]) q.push(i);
    }
    res.push_back(current);
}

//Need to reverse the answer as ideally we should have gone back from a vertex, but we are going in the forward direction
void dfs(vector<vector<int>> adj, int current){
    vis[current]=true;
    for(auto i : adj[current])
        if(!vis[i])
            dfs(adj,i);
    res.push_back(current);
}

int main(){
    int t; cin>>t;
    while(t--){
        int e,v; cin>>e>>v;
        vector<vector<int>> adjList(v);
        for(int i=0;i<e;i++){
            int from,to; cin>>from>>to;
            adjList[from].push_back(to);                //if doing the conventional way, reverse the res obtained to get the answer
        }
        vis = new bool[v]; for(int i=0;i<v;i++) vis[i]=0;
        res.clear();
        for(int i=0;i<v;i++){
            if(!vis[i]){
                  dfs(adjList,i);
            }
        }
        reverse(res.begin(),res.end());
        for(auto i : res)
            cout<<i<<" ";
        cout<<endl; res.clear();

        indegree=new int[v]; for(int i=0;i<v;i++) indegree[i]=0;
        for(int i=0;i<v;i++)
            for(auto to : adjList[i])
                indegree[to]++;

        for(int i=0;i<v;i++)
            if(indegree[i]==0)
                q.push(i);

        while(!q.empty()){
            kahnTopSort(adjList,q.front());
            q.pop();
        }

        for(auto i : res)
            cout<<i<<" ";
        cout<<endl;

    }
}

/*
1
6 6
5 0 5 2 2 3 4 0 4 1 1 3
*/

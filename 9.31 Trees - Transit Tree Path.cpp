//https://atcoder.jp/contests/abc070/tasks/abc070_d

#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define ll long long


int v;
ll depth[100001]={};
bool vis[100001] = {};
map<int,vector<pair<int,int>>> adjList;

void dfs(int root){

    vis[root]=1;
    for(auto i : adjList[root]){
        if(!vis[i.first]){
            depth[i.first]=depth[root]+i.second;
            dfs(i.first);
        }
    }

}

int main(){

    cin>>v;
    int from,to,wt;

    for(int i=0;i<v-1;i++){
        cin>>from>>to>>wt;
        adjList[from].push_back({to,wt});
        adjList[to].push_back({from,wt});
    }

    int q,k;
    cin>>q>>k;

    dfs(k);

    for(int i=0;i<q;i++){
        cin>>from>>to;
        cout<<depth[from]+depth[to]<<endl;
    }

}

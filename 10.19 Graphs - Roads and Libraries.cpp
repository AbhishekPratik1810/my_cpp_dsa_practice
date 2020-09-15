//https://www.hackerrank.com/challenges/torque-and-development/problem

#include<iostream>
#include<map>
#include<vector>
using namespace std;

#define ll long long

bool vis[100001];
int v,e;
ll tc,rc;
ll cities;
map<int,vector<int>> adjList;

void dfs(int src){

    vis[src]=1;
    cities++;
    for(auto i : adjList[src]){
        if(!vis[i])
            dfs(i);
    }


}

ll minCost(){

    ll cost=0;

    for(int i=1;i<=v;i++){
        if(!vis[i]){
            cities=0;
            dfs(i);
            ll onlyTemples = tc*cities;
            ll oneTemple = (ll) tc + (cities-1)*((ll)rc);
            cost+=min(onlyTemples,oneTemple);
        }
    }
    return cost;
}


int main(){

    int t,from,to;
    cin>>t;

    while(t--){

        cin>>v>>e>>tc>>rc;

        adjList.clear();
        for(int i=1;i<=v;i++) vis[i]=0;

        for(int i=1;i<=e;i++){
            cin>>from>>to;
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }

        cout<<minCost()<<endl;

    }


}

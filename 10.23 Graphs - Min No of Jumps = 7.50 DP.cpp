//Not very efficient as while adding edges to the graph, it will take O(n^2) time for a complete graph
//https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number/0
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

int v,mxN=1e9;
map<int,vector<int>> adjList;
int dis[10000001];

void bfs(int src){


    vector<bool> vis(v+1,0);

    queue<int> q;
    q.push(src);
    vis[src]=1;
    dis[src]=0;

    while(!q.empty()){
        src=q.front();
        q.pop();
        for(auto i : adjList[src]){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
                dis[i]=dis[src]+1;
            }
        }
    }

}

int main(){

    int t,jump;cin>>t;

    while(t--){

        cin>>v;

        for(int i=0;i<=v;i++) dis[i]=mxN;
        adjList.clear();

        for(int i=1;i<=v;i++){

            cin>>jump;

            if(jump!=0){
                for(int j=1;j<=jump;j++){               //If jumps=O(v), this will take O(v^2) for initialization itself
                    if(i+j<=v)
                        adjList[i].push_back(i+j);
                    else
                        adjList[i].push_back(v);
                }
            }

        }

        bfs(1);

        cout<<(dis[v]==mxN?-1:dis[v])<<endl;

    }

}



#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,int> lPair;
map<int,vector<pair<int,ll>>> adjList;

ll maxDist = 1e17;

void dijkstra(int src, int des){

    vector<ll> dist(des+1,maxDist); dist[src]=0;
    vector<int> parent(des+1); parent[1]=-1;
    vector<bool> vis(des+1,0);
    priority_queue<lPair,vector<lPair>,greater<lPair>> pq;
    pq.push(make_pair(0,src));              //dist,vertex

    while(!pq.empty()){

        int minVtx = pq.top().second; pq.pop();
        if(vis[minVtx]) continue;                                       //Maybe reqd to not unnecessarily go through adjList[outdated] vertex again
        vis[minVtx]=1;                                                  //Ek teer do nishana. Neither do we constantly traverse in a cycle, nor is the "outdated" minVertex being counted
        for(auto &currPair : adjList[minVtx]){
            ll currVtx = currPair.first,currWt = currPair.second;
            if(!vis[currVtx] && dist[minVtx]+currWt<dist[currVtx]){
                dist[currVtx]=dist[minVtx]+currWt;
                pq.push(make_pair(dist[currVtx],currVtx));
                parent[currVtx]=minVtx;
            }
        }

    }

    if(dist[des]==maxDist)
        cout<<-1<<endl;
    else{

        vector<int> path; path.push_back(des);
        int curr = des;

        while(parent[curr]!=-1){
            path.push_back(parent[curr]);
            curr=parent[curr];
        }

        for(int i=path.size()-1;i>=0;i--)
            cout<<path[i]<<" ";
        cout<<endl;
    }

}

void dijkstraSet(int src,int des){

    set<pair<ll,int>> s;                    //dist,vtx
    vector<bool> isTakenCare(des+1,0);
    vector<ll> dist(des+1,maxDist);
    vector<int> parent(des+1);

    s.insert(make_pair(0,src));
    dist[1]=0;
    parent[1]=-1;

    while(!s.empty()){
        int minVtx = (*(s.begin())).second;
        isTakenCare[minVtx]=1;
        s.erase(s.begin());
        for(auto &p : adjList[minVtx]){
            int currVtx=p.first; ll wt = p.second;
            if(!isTakenCare[currVtx] && dist[minVtx]+wt<dist[currVtx]){
                dist[currVtx]=dist[minVtx]+wt;
                s.insert(make_pair(dist[currVtx],currVtx));
                parent[currVtx]=minVtx;
            }
        }
    }

    if(dist[des]==maxDist){
        cout<<-1<<endl;
    }else{
        vector<int> path;
        int curr = des;

        path.push_back(des);

        while(parent[curr]!=-1){
            path.push_back(parent[curr]);
            curr=parent[curr];
        }

        for(int i=path.size()-1;i>=0;i--)
            cout<<path[i]<<" ";
        cout<<endl;

    }


}


int main(){

    int n,m; cin>>n>>m;

    int from,to,wt;
    for(int i=1;i<=m;i++){
        cin>>from>>to>>wt;
        adjList[from].push_back(make_pair(to,wt));
        adjList[to].push_back(make_pair(from,wt));
    }

    dijkstra(1,n);
    dijkstraSet(1,n);
}

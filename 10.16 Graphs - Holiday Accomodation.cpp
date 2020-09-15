//https://www.spoj.com/problems/HOLI/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>
using namespace std;

typedef long long ll;

ll ans=0;

int dfs(int current,unordered_map<int,vector<pair<int,int>>> &adjList, int connectedComponents[], bool vis[], int vtx){

    int connectedLeft, connectedRight;          //count of all nodes in connected component to the left and right of the edge

    if(!vis[current]){
        vis[current]=1;
        for(auto p : adjList[current]){
            if(!vis[p.first]){
                connectedComponents[current]+=dfs(p.first,adjList,connectedComponents,vis,vtx);
                connectedLeft = connectedComponents[p.first];
                connectedRight = vtx-connectedLeft;
                ans += min(connectedLeft,connectedRight)*2*(p.second);
            }
        }
        return connectedComponents[current];
    }
    return 0;


}

ll accomodate(int vtx,unordered_map<int,vector<pair<int,int>>> &adjList){

    int* connectedComponents = new int[vtx+1];
    bool* vis = new bool[vtx+1];

    for(int i=0;i<=vtx;i++){
        connectedComponents[i]=1;
        vis[i]=0;
    }

    dfs(1,adjList,connectedComponents,vis,vtx);


    /*
        If using edgeList
        int from,to,wt,connectedLeft, connectedRight;
        ll ans=0;
        for(auto v : edgeList){
            from = v[0], to = v[1], wt = v[2];
            connectedLeft = min(connectedComponents[to],connectedComponents[from]);
            connectedRight = vtx-connectedLeft;
            ans = ans + ((ll)min(connectedLeft,connectedRight)*2*wt);
        }

    */

    return ans;

}

int main(){

    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);


    int t,from,to,wt,v,e;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>v; e=v-1;
        unordered_map<int,vector<pair<int,int>>> adjList;

        for(int i=0;i<e;i++){
            cin>>from>>to>>wt;
            adjList[from].push_back(make_pair(to,wt));
            adjList[to].push_back(make_pair(from,wt));
        }

        ans=0;

        cout<<"Case #"<<i<<": "<<accomodate(v,adjList)<<endl;

    }


}

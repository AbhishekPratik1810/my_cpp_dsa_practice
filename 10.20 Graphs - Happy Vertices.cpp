//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/happy-vertices/submissions/

#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;

map<int,vector<int>> adjList;


bool vis[100001]={};
int v;
int parent[100001] = {};
int child[100001]={};


void dfs(int src,int pt){
    vis[src]=1;
    parent[src]=pt;
    child[pt]++;
    for(auto i : adjList[src]){
        if(!vis[i])
            dfs(i,src);
    }

}

int main() {

        int from,to,e;

        cin>>v>>e;

        for(int i=1;i<=e;i++){
            cin>>from>>to;
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }

        int ans=0;
        for(int i=1;i<=v;i++){
            if(!vis[i])
                dfs(i,0);
        }


        for(int i=1;i<=v;i++){
            if(parent[i]==0) continue;
            int parVtxChildCount = adjList[parent[i]].size();
            int currVtxChildCount = adjList[i].size();


            //M1
//            if(parent[parent[i]]==0){                             //=> parent[i] is master parent => parVtxChildCount is correct, but currVtxChildCount is incorrect by 1 as it contains the edge from the parent to itself
//                if(currVtxChildCount-1>parVtxChildCount)
//                    ans++;
//            }else if(currVtxChildCount>parVtxChildCount)          //=> both are increased by 1 => for the difference, it won't matter
//                ans++;

            //M2
            if(child[i]>child[parent[i]])
                ans++;

        }

        cout<<ans<<endl;




	return 0;
}

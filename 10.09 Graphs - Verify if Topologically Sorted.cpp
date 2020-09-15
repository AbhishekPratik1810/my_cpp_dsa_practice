#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//Basically, as all edges go from left to right in a top sorted graph, the position of vertex v2 is always after v1 where an edge connects v1->v2 in the original graph
bool topSorted(vector<int> toVerify, vector<vector<int>> adjList, int v){
    map<int,int> position;
    for(int i=0;i<v;i++)
        position[toVerify[i]]=i;
    for(int v1=0;v1<v;v1++){
        for(auto v2 : adjList[v1])
            if(position[v1]>position[v2])
                return false;
    }
    return true;
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

        vector<int> toVerify;
        for(int i=0;i<v;i++){
            int vtx; cin>>vtx;
            toVerify.push_back(vtx);
        }

        cout<<(topSorted(toVerify,adjList,v)?1:0)<<endl;
    }
}


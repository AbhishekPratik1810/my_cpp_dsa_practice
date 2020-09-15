#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<int,vector<int>> adjList;
int v,e;

void dfs(vector<bool> &visited, int src){
    for(int des : adjList[src]){
        if(!visited[des]){
            visited[des]=1;
            dfs(visited,des);
        }
    }
}


int findSet(int element, vector<int> &parent){
    if(parent[element]==element) return element;
    return parent[element] = findSet(parent[element],parent);
}

void unionByRank(int set1, int set2, vector<int> &parent, vector<int> &rank){
    if(rank[set1]<rank[set2]) swap(set1,set2);          //making rank[set2] as the smallest always and rank[set1] greatest always
    parent[set2]=set1;
    rank[set1]+=rank[set2];
}

int usingDSU(){
    vector<int> parent(v);
    for(int i=0;i<v;i++) parent[i]=i;
    vector<int> rank(v,1);

    for(int from=0;from<v;from++){
        int set1 = findSet(from,parent);
        for(auto to : adjList[from]){
            int set2 = findSet(to,parent);
            unionByRank(set1,set2,parent,rank);
        }
    }

    map<int,int> count;
    for(int i=0;i<v;i++) count[parent[i]]++;

    return count.size();
}

int main(){
    int from,to; cin>>v>>e;

    for(int i=0;i<e;i++){
        cin>>from>>to;
        adjList[from].push_back(to);
    }

    vector<bool> visited(v+1,0);

    int connectedCount=0;
    for(int i=1;i<=v;i++){
        if(!visited[i]){
            connectedCount++;
            visited[i]=1;
            dfs(visited,i);
        }
    }
    cout<<connectedCount<<endl;

    cout<<usingDSU();
}

/*
8 5
1 2
2 3
2 4
3 5
6 7
*/

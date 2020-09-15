/*
There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.

The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.

1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1

Input

5 3
0 1
2 3
0 4

Ans = 6

0 1 4 cannot be reached by 2 hence (2,0) (2,1) (2,4) and also 0 1 4 cannot be reached by 3 so (3,0) (3,1) (3,4) hence 6 ways.

*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int findSet(int element, vector<int> &parent){
    if(parent[element]==element) return element;
    return parent[element] = findSet(parent[element],parent);
}

void unionByRank(int set1, int set2, vector<int> &parent, vector<int> &rank){
   set1=findSet(set1,parent);
   set2=findSet(set2,parent);
    if(set1!=set2){                                         //This is done because, if set1==set2, then we are unnecessarily increasing rank of set2
        if(rank[set1]<rank[set2]) swap(set1,set2);          //making rank[set2] as the smallest always and rank[set1] greatest always
        parent[set2]=set1;
        rank[set1]+=rank[set2];
    }
}

long long nC2(long long v){
    return (v*(v-1))/2;
}

int main(){

    int v,e,from,to; cin>>v>>e;

    map<int,vector<int>> adjList;

    for(int i=0;i<e;i++){
        cin>>from>>to;
        adjList[from].push_back(to);
    }

    vector<int> parent(v);
    for(int i=0;i<v;i++) parent[i]=i;
    vector<int> rank(v,1);

    for(from=0;from<v;from++)
        for(auto to : adjList[from])
            unionByRank(from,to,parent,rank);



    map<int,int> count;
    for(int i=0;i<v;i++) count[findSet(i,parent)]++;            //Lesson to learn, never use parent[i], always use findSet(i,parent) to get the parent

    /*
    Sasta Tareeka
    long long ans=0;
    int size = store.size();
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++)
            ans+= store[i]*store[j];
    }
    cout<<ans<<endl;
    */

    long long totalWays = nC2(v);               //Total Ways of selecting 2 cities from v cities
    long long ways = 0;                         //Number of ways to select 2 cities inside the same connected component

    for(auto p:count)
		ways+= nC2(p.second);


    cout<<totalWays-ways<<endl;

    long long ans=0;
    for(int i=0;i<v;i++)
        ans+=v-rank[findSet(i,parent)];                         //Same lesson to learn, never use parent[i], always use findSet(i,parent) to get the parent
    cout<<ans/2<<endl;
}

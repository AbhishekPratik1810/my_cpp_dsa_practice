#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;

int findSet(int element, vector<int> &parent){
    if(parent[element]==element) return element;
    return parent[element] = findSet(parent[element],parent);
}

void unionByRank(int set1, int set2, vector<int> &parent, vector<int> &rank){

    if(set2<set1) swap(set1,set2);          //making set1 always smaller
    parent[set1]=set2;
    rank[set2]+=rank[set1];

}


int anotherWayOfInitEdgeList(){
    int v,e,from,to,wt; cin>>v>>e;
    vector<vector<int>> edgeList(e);        //Jab Edge Traversal Hai => edgeList

    for(int i=0;i<e;i++){
        cin>>from>>to>>wt;
        edgeList[i]={wt,from,to};
    }

    sort(edgeList.begin(),edgeList.end());

    vector<int> parent(v+1); for(int i=0;i<=v;i++) parent[i]=i;
    vector<int> rank(v+1,1);

    int minCost=0,set1,set2;

    for(int i=0;i<e;i++){
        wt = edgeList[i][0], from = edgeList[i][1], to = edgeList[i][2];
        set1 = findSet(from,parent);
        set2 = findSet(to,parent);
        if(set1!=set2){
            unionByRank(set1,set2,parent,rank);
            minCost+=wt;
        }
    }

    return minCost;
}

int main(){


//    int v,e,from,to,wt; cin>>v>>e;
//
//    map<int,vector<pair<int,int>>> edgeList;
//
//    for(int i=1;i<=e;i++){
//        cin>>from>>to>>wt;
//        edgeList[wt].push_back(make_pair(from,to));
//    }
//
//    int minCost = 0;
//    vector<int> parent(v+1);
//    for(int i=0;i<=v;i++) parent[i]=i;
//    vector<int> rank(v+1,1);
//
//    for(auto p : edgeList){
//        wt=p.first;
//        for(auto edge : p.second){
//            from=edge.first, to = edge.second;
//            int set1=findSet(from,parent), set2=findSet(to,parent);
//            if(set1!=set2){
//                unionByRank(set1,set2,parent,rank);
//                minCost+=wt;
//            }
//        }
//    }

    cout<<anotherWayOfInitEdgeList()<<endl;

}

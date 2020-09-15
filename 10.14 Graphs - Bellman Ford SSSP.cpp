//https://practice.geeksforgeeks.org/problems/negative-weight-cycle/0

#include<iostream>
#include<map>
#include<vector>
#include<utility>
#include<climits>

using namespace std;

int main(){

    int t; cin>>t;
    while(t--){

        int v,e,from,to,wt; cin>>v>>e;

        //map<int,vector<pair<int,int>>> adjList;

        vector<vector<int>> edgeList(e);

        for(int i=0;i<e;i++){
            cin>>from>>to>>wt;
            edgeList[i]={from,to,wt};
        }

        vector<int> dis(v,INT_MAX);
        dis[0]=0;

        for(int i=1;i<=v-1;i++){
            for(auto e : edgeList){
                from=e[0],to=e[1],wt=e[2];
                if(dis[from]!=INT_MAX && dis[from]+wt<dis[to]) dis[to] = dis[from]+wt;
            }
        }

        //Neg Weight Cycle Detection
        bool ok=false;
        for(auto e : edgeList){
            from=e[0],to=e[1],wt=e[2];
            if(dis[from]!=INT_MAX && dis[from]+wt<dis[to]) ok=true;
        }
        cout<<ok<<endl;
    }

}

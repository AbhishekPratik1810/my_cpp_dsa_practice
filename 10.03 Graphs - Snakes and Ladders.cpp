#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph{

private:
    vector<int> col;
    vector<vector<int>> adjList;
    vector<int> shortestPath;

public:
    Graph() : col(0),adjList(31,col),shortestPath(31,0){

    }
    void addEdge(int start,int last){
        adjList[start].push_back(last);
    }

    int bfs(int start,int last){
        queue<int> q;
        vector<bool> vis(31,false);
        q.push(start);
        vis[start]=true;
        while(!q.empty()){
            start=q.front();
            q.pop();
            for(auto square : adjList[start]){
                if(!vis[square]){
                    vis[square]=true;
                    shortestPath[square]=1+shortestPath[start];
                    q.push(square);
                }
            }
        }
        return shortestPath[last];
    }

};

int solve(){
    int n; cin>>n;
    Graph board;
    vector<int> destination(31,-1);

    for(int i=0;i<n;i++){
        int key,val; cin>>key>>val;
        destination[key]=val;
    }
    for(int i=1;i<=30;i++){
        for(int j=1;j<=6;j++){
            if(i+j>30)
                continue;
            if(destination[i+j]!=-1)
                board.addEdge(i,destination[i+j]);
            else{
                board.addEdge(i,i+j);
            }
        }
    }
    return board.bfs(1,30);

}

int main(){
    int t; cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}

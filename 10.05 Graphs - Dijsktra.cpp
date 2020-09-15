#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<utility>    //for pair
#include<set>
#include<algorithm>
#include<map>
using namespace std;

class Graph{

    private:
        vector<vector<pair<int,int>>> adjList;

    public:
        Graph(vector<vector<pair<int,int>>> v) : adjList(v){
        }

        void addEdge(int start,int last,int weight){
            adjList[start].push_back(make_pair(last,weight));
        }

        void bfs(int start, int n){
            queue<int> q;
            bool* vis = new bool[n+1]; for(int i=0;i<=n;i++) vis[i]=false;
            q.push(start);
            vis[start]=true;
            while(!q.empty()){
                start=q.front(); q.pop();
                for(auto p : adjList[start]){
                    if(!vis[p.first]){
                        q.push(p.first);
                        vis[p.first]=true;
                        cout<<"Edge from "<<start<< " to "<< p.first <<" of weight "<<p.second<<endl;
                    }
                }
            }
        }

        int dijsktra(int source, int target, int n){
            cout<<"The shortest path from "<<source<<" to "<<target<<" is: ";

            int* delta = new int[n+1]; delta[1]=0; for(int i=2;i<=n;i++) delta[i]=INT_MAX;
            stack<int> visited;
            bool* vis = new bool[n+1]; for(int i=1;i<=n;i++) vis[i]=false;
            vector<vector<char>> path(n+1); path[1].push_back(source+'0');

            while(visited.size()!=n){

                vis[source]=true; visited.push(source);
                for(auto p : adjList[source])
                    if(!vis[p.first]){
                        if(delta[source]+p.second<delta[p.first]){
                            path[p.first]=path[source];
                            path[p.first].push_back(p.first+'0');
                            delta[p.first]=delta[source]+p.second;
                        }
                    }

                int temp=INT_MAX,newSource;
                for(int i=1;i<=n;i++){
                    if(!vis[i] && delta[i]<temp){
                        temp=delta[i];
                        newSource=i;
                    }
                }
//                cout<<"After Visiting Source "<<source<<" successfully "<<endl;
//                for(int i=1;i<=n;i++)
//                    cout<<delta[i]<<" "<<" ";
//                cout<<endl;

                source=newSource;
            }

            for(auto c : path[target])
                cout<<c<<" ";
            cout<<"\nThe shortest distance between them is: ";

            return delta[target];
        }


};


int main(){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> v(n+1);
    Graph g(v);
    int start,last,wt;
    for(int i=0;i<m;i++){
        cin>>start>>last>>wt;
        g.addEdge(start,last,wt);
    }

    cout<<g.dijsktra(1,n,n)<<endl;
}

/*
8 15
1 2 9
1 6 14
1 7 15
2 3 24
6 3 18
6 7 5
6 5 30
7 5 20
7 8 44
5 8 16
5 4 11
4 3 6
4 8 6
3 8 19
3 5 2
*/


/*

8 13
1 2 9
1 3 6
1 5 13
2 6 10
3 4 30
3 6 18
4 7 11
4 8 16
5 8 25
6 4 6
7 6 6
7 8 6
3 5 8
*/

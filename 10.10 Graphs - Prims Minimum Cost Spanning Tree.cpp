//Only for undirected graph
#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}

//Brute Force O(V*V*log(V))
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    int ans=0,count=0;
    vector<bool> vis(V+1,0);
    set<pair<int,pair<int,int>>> s;

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]!=INT_MAX)
                s.insert(make_pair(graph[i][j],make_pair(i,j)));
        }
    }

    while(count!=V-1){
        int weight = (*(s.begin())).first;
        pair<int,int> edge = (*(s.begin())).second;
        int from = edge.first, to = edge.second;
        if(!(vis[from]&&vis[to])){
            vis[from]=1,vis[to]=1;
            ans+=weight;
            count++;
        }
        s.erase(s.begin());
    }

    return ans;
}
//O(Elog(V))  same can be implemented using priority queue
int primsAlgorithm(int V, int E, vector<vector<int>> &graph){

    vector<int> dist(V,INT_MAX);
    set<pair<int,int>> s;
    vector<bool> vis(V,0);
    int ans=0;

    dist[0]=0;
    s.insert(make_pair(0,0));
    vis[0]=1;

    while(!s.empty()){
        int minVtx = (*(s.begin())).second;
        s.erase(s.begin());
        for(int i=0;i<V;i++){
            if(!vis[i]&& graph[minVtx][i]<dist[i]){
                auto it = s.find(make_pair(dist[i],i));
                if(it!=s.end())
                    s.erase(it);
                dist[i]=graph[minVtx][i];
                s.insert(make_pair(dist[i],i));
            }
        }
        vis[minVtx]=1;
        ans+=dist[minVtx];
    }

    return ans;
}

int usingPQ(){

    int v,e,from,to,wt; cin>>v>>e;
    map<int,vector<pair<int,int>>> adjList;     //Jab Vertex Traversal Hai => adjList

    for(int i=0;i<e;i++){
        cin>>from>>to>>wt;
        adjList[from].push_back(make_pair(wt,to));
        adjList[to].push_back(make_pair(wt,from));
    }

    long long minCost = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> vis(v+1,0);
    vector<int> dis(v+1,0);


    pq.push(make_pair(0,1));

    while(!pq.empty()){

        wt=(pq.top()).first;
        from = (pq.top()).second;
        pq.pop();

        if(!vis[from]){

            vis[from]=1;
            minCost+=wt;

            for(auto to : adjList[from])
                if(!vis[to.second] && to.first<dis[to.second]){
                    pq.push(to);
                    dis[to.second] = to.first;
                }
        }

    }
    return minCost;
}

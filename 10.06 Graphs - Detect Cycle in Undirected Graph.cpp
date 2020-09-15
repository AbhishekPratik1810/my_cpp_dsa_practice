// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

bool* vis; int* parent;
vector<int> ancestor;
bool ok;

//Core idea if a vertex is encountered such that it is visited before and it is not "parent" of current vertex => this will create a cycle
//Diff b/w this and for directed graph is, here the vertex encountered can be any vertex, as long as it is not the parent. There, the vertex encountered must be an ancestor
bool bfs(vector<int> g[],int current){
    queue<int> q;
    q.push(current); vis[current]=true;
    while(!q.empty()){
        current=q.front(); q.pop();
        for(auto i :g[current]){
            if(!vis[i]){
                vis[i]=true;
                q.push(i);
                parent[i]=current;
            }else if(i!=parent[current])
                return true;
        }
    }
    return false;
}

bool elegantDFS(vector<int> g[],int current,int parent){
    vis[current]=true;
    for(auto i:g[current]){
        if(!vis[i]){
            if(elegantDFS(g,i,current))                     //else continue for other vertices
                return true;
        }
        else if(i!=parent)
            return true;

    }
    return false;
}

//Limitation with below code: doesn't check for loops in a graph
bool dfs(vector<int> g[],int current){
    vis[current]=true;
    ancestor.push_back(current);
    for(auto i:g[current]){
        if(!vis[i])
            dfs(g,i);
        else if(find(ancestor.begin(),ancestor.end()-2,i)!=(ancestor.end()-2))          //Since each edge is 2-way, we don't want to count current edge, and the prev edge in ancestor as they correspond to loops and parallel edges
            return ok=true;

    }
    auto idx=find(ancestor.begin(),ancestor.end(),current);
    ancestor.erase(idx);
    return ok;
}

//Use the fact that for an undirected graph, if noOfEdges >= 2*noOfVertices => There is an edge, as for n vertices, there exist n-1 edges to make a tree.
//=> >=n edges gives a cycle. Also note that for the undirected graph, each edge is 2 way, hence the condition e>=2*v
bool magic(vector<int> g[],int current){

    stack<int> st;
    st.push(current);
    vis[current]=true;
    vector<int> vertices;
    while(!st.empty()){
        current = st.top(); st.pop();
        vertices.push_back(current);
        for(auto i:g[current]){
            if(!vis[i]){
                vis[i]=true;
                st.push(i);
            }
        }
    }
    int v=vertices.size();
    int e=0;

    for(auto i : vertices){
        e+=g[i].size();
    }
    return e>=2*v;

}

bool isCyclic(vector<int> g[], int V)
{
   // Your code here
    vis = new bool[V]; ancestor.clear();ok=false; parent=new int[V];
    for(int i=0;i<V;i++) vis[i]=0,parent[i]=-1;
    for(int i=0;i<V;i++){
        if(!vis[i]){                        //can be written as if(!vis[i] && dfs(g,i)
            if(bfs(g,i))                    //if(elegantDFS(g,i))
                return true;                //  return true;
        }
    }

    return false;

}

// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends


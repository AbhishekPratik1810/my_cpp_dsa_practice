// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool* vis; bool* progress;
bool* ances;
vector<int> ancestor;
bool ok;

//Problem here is, that unlike undirected graph, where the encountered vertex can also be in same level, bfs also works directly.
//Here, we specifically want the vertex encountered to be an ancestor, however level order traversal will never be able to give ancestors of a vertex, dfs can do that easily
bool topSortDFS(vector<int> g[],int current){           //How similar to fasterDFS :P

    vis[current]=true; progress[current]=true;
    for(auto i : g[current]){
        if(!vis[i])
            topSortDFS(g,i);
        else if(progress[i])
            return ok=true;
    }
    progress[current]=false;
    return ok;
}

bool fasterDFS(vector<int> g[],int current){
    vis[current]=true; ances[current]=true;
    for(auto i:g[current]){
        if(!vis[i])
            fasterDFS(g,i);
        else if(ances[i])
            return ok=true;
    }
    ances[current]=false;
    return ok;
}

//Recursion
bool dfs(vector<int> adj[],int current){
    vis[current]=true;
    ancestor.push_back(current);
    for(auto i:adj[current]){
        if(!vis[i])
            dfs(adj,i);
        else if(find(ancestor.begin(),ancestor.end(),i)!=ancestor.end())
            return ok=true;
    }
    auto idx = find(ancestor.begin(),ancestor.end(),current);
    ancestor.erase(idx);
    return ok;
}

//Iterative. This is similar to recursion only,as stack is popped only when all the nodes are visited from a current node
bool magic(vector<int> adj[],int current){

    stack<int> st; st.push(current); vis[current]=true;

    outer : while(!st.empty()){
        current = st.top();
        for(auto i : adj[current]){
            if(!vis[i]){
                vis[i]=true;
                st.push(i);
                goto outer;
            }else{
                stack<int> temp=st;
                while(!temp.empty()){
                    int elt = temp.top(); temp.pop();
                    if(elt==i)
                        return true;
                }
            }
        }
        st.pop();
    }
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vis= new bool[V]; ances=new bool[V]; progress=new bool[V];
    for(int i=0;i<V;i++) vis[i]=false,ances[i]=false,progress[i]=false;
    ancestor.clear();ok=false;                          //for dfs
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(topSortDFS(adj,i))
                return true;
        }
    }
    return false;

}

// { Driver Code Starts.

int main() {

	int t;
	cin >> t;

	while(t--){

	    int v, e;
	    cin >> v >> e;

	    vector<int> adj[v];

	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }

	    cout << isCyclic(v, adj) << endl;

	}

	return 0;
}  // } Driver Code Ends

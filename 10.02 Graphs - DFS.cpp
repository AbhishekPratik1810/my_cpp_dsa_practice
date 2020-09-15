//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/

vector<int> help(vector<int> g[], int key, vector<int> &result, vector<bool> &vis){
    if(!vis[key]){
        result.push_back(key);
        vis[key]=true;
        for(auto i:g[key]){
            help(g,i,result,vis);
        }
    }
    return result;
}

vector <int> dfs(vector<int> g[], int N){
     vector<bool> vis(N,0);
     vector<int> result;
     return help(g,0,result,vis);
}

vector <int> dfsItr(vector<int> g[], int N){
    vector<int> exp; exp.push(0);
    stack<int> st; st.push(0);
    bool* vis = new bool[N]; for(int i=0;i<N;i++) bool[i]=false; vis[0]=true;
    int current;
    outer : while(!st.empty()){
        current=st.top();
        for(auto i:g[current])
            if(!vis[i]){
                vis[i]=true;st.push(i);exp.push(i);
                goto outer;
            }
        st.pop();
    }
    delete[] vis;
    vis=NULL;
    return exp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;

        vector<int> g[N];
        bool vis[N];

        memset(vis, false, sizeof(vis));

        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends

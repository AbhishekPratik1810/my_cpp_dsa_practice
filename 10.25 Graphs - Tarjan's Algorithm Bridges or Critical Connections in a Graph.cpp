//https://leetcode.com/problems/critical-connections-in-a-network/
//https://www.youtube.com/watch?v=bmyyxNyZKzI&t=917s

/*
Deepest Backedge is the main thing we want to look for. Why? because any vertex in between the deepest backedge vertex and current vertex(plus ancestors) will never give a bridge


*/

    #include<iostream>

    using namespace std;

    map<int,vector<int>> adjList;
    vector<vector<int>> res;
    int time=0;
    int* deepestBackEdge;
    int* arrivalTime;

    void dfs(int src, int parent, vector<bool> &vis){

        arrivalTime[src]=deepestBackEdge[src]=time++;
        vis[src]=1;

        for(auto to : adjList[src]){

            if(!vis[to]){

                dfs(to,src,vis);

                deepestBackEdge[src] = min(deepestBackEdge[to],deepestBackEdge[src]);

                //Checking if Bridge exists
                if(deepestBackEdge[to]>arrivalTime[src])
                    res.push_back({src,to});                //Found Bridge


            }else if(to!=parent){

                deepestBackEdge[src] = min(deepestBackEdge[src],arrivalTime[to]);

            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {


        for(auto i : connections){
            int from = i[0], to = i[1];
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }

        vector<bool> vis(n,0);

        deepestBackEdge = new int[n];
        arrivalTime = new int[n];

        dfs(0,-1,vis);

        return res;


    }

// { Driver Code Starts
// C++ program to find out whether a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--)
	{
		memset(g,0,sizeof (g));
		int n;
		cin>>n;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}

		cout<<isBipartite(g,n)<<endl;
	}
	return 0;
}

//M1: uses the coloring concept

bool oddCycle = 0;
int v;

void dfs(int currVtx, int currColor, int col[], int parent, int adjMat[][MAX]){
    if(!col[currVtx]){
        col[currVtx]=currColor;

        for(int i=0;i<v;i++){
            if(adjMat[currVtx][i]){
                if(!col[i]){
                    dfs(i,3-currColor,col,currVtx,adjMat);                  //If currColor = 1 => Next color = 2, if currColor = 2 => Next Color = 1
                }else if(i!=parent && currColor == col[i]){
                    oddCycle = 1;
                }
            }
        }

    }
    return;
}

bool isBipartite(int adjMat[][MAX],int V)
{

    int col[V]={};  //0 => not colored => not visited
    v = V;

    for(int i=0;i<v;i++){
        oddCycle = 0;
        if(!col[i]){
            dfs(i,1,col,-1,adjMat);
            if(oddCycle) return 0;
        }

    }

    return 1;

}


//The below method will also help to find the length of the cycle
/*
bool check = true;
int ctr = 0;
bool dfs(int curr, int adjMat[][MAX],int v,int count[], bool vis[], int parent[]){
    if(!vis[curr]){
        vis[curr]=1;
        for(int i=0;i<v;i++){
            if(adjMat[curr][i]){
                if(vis[i] && i!=parent[curr]){
                    count[i]=ctr-count[i];
                    if(!(count[i]%2)) return check=false;
                }else{
                    count[i]=(++ctr);
                    parent[i]=curr;
                    dfs(i,adjMat,v,count,vis,parent);
                }
            }
        }
    }
    return check;
}

bool isBipartite(int adjMat[][MAX],int v)
{
    bool* vis = new bool[v];
    int* parent = new int[v];
    int* count = new int[v];
    for(int i=0;i<v;i++){
        vis[i]=0;
        count[i]=0;
        parent[i]=-1;
    }



    for(int i=0;i<v;i++){
        bool ok=1;
        check = true;
        ctr=0;
        if(!vis[i]){
            ok = dfs(i,adjMat,v,count,vis,parent);
            if(!ok) return false;
        }
    }
    return true;

}
*/

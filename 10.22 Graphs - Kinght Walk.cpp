//https://practice.geeksforgeeks.org/problems/knight-walk/0

#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int mxN = 1e9;
int v,e,rowK,colK,rowT,colT;

vector<int> dis(626);

int unMask(int x,int y){
    return (x-1)*e+y;
}

bool isPossible(int cRow, int cCol){
    return (cRow>=1 && cRow<=v && cCol>=1 && cCol<=e);
}

int dx[]={-1,-1,1,1,-2,-2,2,2};
int dy[]={-2,2,-2,2,-1,1,-1,1};

void elegantBFS(int cRow, int cCol){

    int vtx = unMask(cRow,cCol),cV;

    dis[vtx]=0;

    queue<pair<int,int>> q;

    q.push({cRow,cCol});

    vector<bool> vis(626,0);
    vis[vtx]=1;

    while(!q.empty()){

        cRow = q.front().first, cCol = q.front().second;
        q.pop();
        vtx = unMask(cRow,cCol);

        for(int i=0;i<8;i++){

            int postMoveX = cRow+dx[i], postMoveY  = cCol + dy[i];

            if(isPossible(postMoveX,postMoveY)){

                cV = unMask(postMoveX,postMoveY);
                if(!vis[cV]){
                    q.push({cRow+dx[i],cCol+dy[i]});
                    vis[cV]=1;
                }

                dis[cV]=min(dis[cV],dis[vtx]+1);            //It maybe that the distance which was obtained by visiting it previously
            }
        }

    }


}


int main(){

    int t; cin>>t;
    while(t--){

        cin>>v>>e;

        for(int i=0;i<=(v*e);i++) dis[i]=mxN;

        cin>>rowK>>colK>>rowT>>colT;

        elegantBFS(rowK,colK);

        cout<<(dis[unMask(rowT,colT)]==mxN?-1:dis[unMask(rowT,colT)])<<endl;            //Note here the knight may never reach the cell

    }

}

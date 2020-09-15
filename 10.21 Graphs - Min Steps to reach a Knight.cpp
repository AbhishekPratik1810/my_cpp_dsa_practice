//https://practice.geeksforgeeks.org/problems/steps-by-knight/0

#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int mxN = 1e9;
int v,rowK,colK,rowT,colT;

vector<int> dis(401);

int unMask(int x,int y){
    return (x-1)*v+y;
}

bool isPossible(int cRow, int cCol){
    return (cRow>=1 && cRow<=v && cCol>=1 && cCol<=v);
}

int dx[]={-1,-1,1,1,-2,-2,2,2};
int dy[]={-2,2,-2,2,-1,1,-1,1};

void elegantBFS(int cRow, int cCol){

    int vtx = unMask(cRow,cCol),cV;

    dis[vtx]=0;

    queue<pair<int,int>> q;

    q.push({cRow,cCol});

    vector<bool> vis(401,0);
    vis[vtx]=1;

    while(!q.empty()){

        cRow = q.front().first, cCol = q.front().second;
        q.pop();
        vtx = unMask(cRow,cCol);

        for(int i=0;i<8;i++){

            int postMoveX = cRow+dy[i], postMoveY  = cCol + dx[i];

            if(isPossible(postMoveX,postMoveY)){

                cV = unMask(postMoveX,postMoveY);
                if(!vis[cV]){
                    q.push({cRow+dy[i],cCol+dx[i]});
                    vis[cV]=1;
                }

                dis[cV]=min(dis[cV],dis[vtx]+1);            //It maybe that the distance which was obtained by visiting it previously
            }
        }

    }


}

//void bfs(int cRow, int cCol){
//
//    int vtx = unMask(cRow,cCol),cV;
//
//    dis[vtx]=0;
//
//    queue<pair<int,int>> q;
//
//    q.push({cRow,cCol});
//
//    vector<bool> vis(401,0);
//    vis[vtx]=1;
//
//    while(!q.empty()){
//
//        cRow = q.front().first, cCol = q.front().second;
//        q.pop();
//        vtx = unMask(cRow,cCol);
//
//        if(isPossible(cRow-1,cCol-2)){
//
//            cV=unMask(cRow-1,cCol-2);
//            if(!vis[cV]){
//                q.push({cRow-1,cCol-2});
//                vis[cV]=1;
//            }
//            dis[cV]=min(dis[cV],dis[vtx]+1);
//        }
//        if(isPossible(cRow-1,cCol+2)){
//            cV=unMask(cRow-1,cCol+2);
//            if(!vis[cV]){
//                q.push({cRow-1,cCol+2});
//                vis[cV]=1;
//            }
//            dis[cV]=min(dis[cV],dis[vtx]+1);
//        }
//        if(isPossible(cRow+1,cCol-2)){
//            cV=unMask(cRow+1,cCol-2);
//            if(!vis[cV]){
//                q.push({cRow+1,cCol-2});
//                vis[cV]=1;
//            }
//            dis[cV]=min(dis[cV],dis[vtx]+1);
//        }
//        if(isPossible(cRow+1,cCol+2)){
//            cV=unMask(cRow+1,cCol+2);
//            if(!vis[cV]){
//                q.push({cRow+1,cCol+2});
//                vis[cV]=1;
//            }
//            dis[cV]=min(dis[cV],dis[vtx]+1);
//        }
//
//        if(isPossible(cRow+2,cCol-1)){
//            cV=unMask(cRow+2,cCol-1);
//            if(!vis[cV]){
//                q.push({cRow+2,cCol-1});
//                vis[cV]=1;
//            }
//            dis[cV]=min(dis[cV],dis[vtx]+1);
//        }
//        if(isPossible(cRow+2,cCol+1)){
//            cV=unMask(cRow+2,cCol+1);
//            if(!vis[cV]){
//                q.push({cRow+2,cCol+1});
//                vis[cV]=1;
//            }
//            dis[cV]=min(dis[cV],dis[vtx]+1);
//        }
//        if(isPossible(cRow-2,cCol-1)){
//            cV=unMask(cRow-2,cCol-1);
//            if(!vis[cV]){
//                q.push({cRow-2,cCol-1});
//                vis[cV]=1;
//            }
//            dis[cV]=min(dis[cV],dis[vtx]+1);
//        }
//        if(isPossible(cRow-2,cCol+1)){
//            cV=unMask(cRow-2,cCol+1);
//            if(!vis[cV]){
//                q.push({cRow-2,cCol+1});
//                vis[cV]=1;
//            }
//            dis[cV]=min(dis[cV],dis[vtx]+1);
//        }
//
//
//    }
//
//
//}


int main(){

    int t; cin>>t;
    while(t--){

        cin>>v;

        for(int i=0;i<=(v*v);i++) dis[i]=mxN;

        cin>>rowK>>colK>>rowT>>colT;

        elegantBFS(rowK,colK);

        cout<<dis[unMask(rowT,colT)]<<endl;



    }


}

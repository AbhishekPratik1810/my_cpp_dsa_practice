//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}

int dx[] = {0,-1,1,1,-1,0,1,-1};
int dy[] = {1,1,1,0,0,-1,-1,-1};

int row,col;

bool isPossible(int x,int y,vector<vector<bool>> &vis,vector<int> A[]){
    return (x>=0 && x<row && y>=0 && y<col && !vis[x][y] && A[x][y]);
}

void dfs(int cRow, int cCol, vector<vector<bool>> &vis,vector<int> A[]){

    vis[cRow][cCol]=1;

    for(int k=0;k<8;k++){
        if(isPossible(cRow+dx[k],cCol+dy[k],vis,A))
            dfs(cRow+dx[k],cCol+dy[k],vis,A);
    }

}

int findIslands(vector<int> A[], int N, int M) {

    vector<vector<bool>> vis(N,vector<bool> (M));
    row = N, col = M;
    int ans=0;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j] && !vis[i][j]){
                ans++;
                dfs(i,j,vis,A);
            }
        }
    }

    return ans;
}

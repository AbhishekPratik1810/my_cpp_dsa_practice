//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include <bits/stdc++.h>
using namespace std;

#define MAX 5

void help(int m[MAX][MAX],int n, string curr, vector<string> &res, int row, int col, vector<vector<bool>> &vis){

    if(row<0 || row>n-1 || col<0 || col>n-1 || !m[row][col] || vis[row][col])
        return;

    vis[row][col]=1;                            //Currently this path is taken, don't come back to it

    if(row==n-1 && col==n-1)
        res.push_back(curr);

    help(m,n,curr+"D",res,row+1,col,vis);
    help(m,n,curr+"L",res,row,col-1,vis);
    help(m,n,curr+"R",res,row,col+1,vis);
    help(m,n,curr+"U",res,row-1,col,vis);

    vis[row][col]=0;                           //Not taken anymore, let any other path explore this again, as it will become a new path!


}


vector<string> printPath(int m[MAX][MAX], int n) {

    vector<string> res;
    vector<vector<bool>> vis(n,vector<bool> (n,0));

    help(m,n,"",res,0,0,vis);

    return res;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}




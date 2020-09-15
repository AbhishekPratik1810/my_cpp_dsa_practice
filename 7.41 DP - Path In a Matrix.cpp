//https://practice.geeksforgeeks.org/problems/path-in-matrix/0

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int minPath(int n, vector<vector<int>> &matrix){

    vector<vector<int>> dp(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++) dp[1][i]=matrix[1][i];

    int ans=INT_MIN;

    for(int row=2;row<=n;row++){

        dp[row][1]=max(dp[row-1][1],dp[row-1][2])+matrix[row][1];
        dp[row][n]=max(dp[row-1][n],dp[row-1][n-1])+matrix[row][n];
        ans=max({ans,dp[row][1],dp[row][n]});
        for(int col=2;col<n;col++){
            dp[row][col]=max({dp[row-1][col],dp[row-1][col-1],dp[row-1][col+1]})+matrix[row][col];
            ans=max(ans,dp[row][col]);
        }
    }

    return ans;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> matrix(n+1,vector<int> (n+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cin>>matrix[i][j];
        }

        cout<<minPath(n,matrix)<<endl;
    }
}

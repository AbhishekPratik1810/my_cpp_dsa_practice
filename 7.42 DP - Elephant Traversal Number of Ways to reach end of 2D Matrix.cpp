#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    dp[1][1]=1;

    for(int row=1;row<=n;row++){
        for(int col=1;col<=n;col++){

            for(int k=1;k<col;k++)
                dp[row][col]+=dp[row][k];

            for(int k=1;k<row;k++)
                dp[row][col]+=dp[k][col];

        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
}

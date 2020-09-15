//https://www.codechef.com/problems/CD1IT4
#include <iostream>
#include<vector>
using namespace std;

int mxN = 1e9+7;

int main() {

	int t; cin>>t;

	while(t--){

	    int row,col,holes;
	    cin>>row>>col>>holes;

	    vector<vector<int>> dp(row, vector<int> (col,-1));

	    for(int i=0;i<holes;i++){
	        int l,m;
	        cin>>l>>m;
	        l--; m--;
	        dp[l][m] = 0;
	    }


	    bool ok = 1;
	    for(int j=0;j<col;j++){
	        if(ok && dp[0][j])
	            dp[0][j]=1;
	        else if(!ok)
	            dp[0][j]=0;
	        else
	            ok = 0;
	    }

	    ok = 1;
	    for(int i=0;i<row;i++){
	        if(ok && dp[i][0])
	            dp[i][0] = 1;
	        else if(!ok)
	            dp[i][0]=0;
	        else
	            ok = 0;
	    }

	    for(int i=1;i<row;i++){
	        for(int j=1;j<col;j++){
	            if(dp[i][j]==0)
	                continue;
	            else
	                dp[i][j] = (dp[i-1][j]%mxN + dp[i][j-1]%mxN)%mxN;
	        }
	    }

	    cout<<dp[row-1][col-1]<<endl;

	}


	return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int row,col,blocked; cin>>row>>col>>blocked;
    static vector<vector<int>> dp(row+1,vector<int> (col+1,0));
    for(int i=0;i<blocked;i++){
        int r,c; cin>>r>>c;
        dp[r][c]=INT_MAX;
    }

    bool ok=true;
    for(int i=1;i<=col;i++) {
            if(dp[1][i]==INT_MAX) ok=false;
            dp[1][i] = ok?1:INT_MAX;
    }
    ok=true;
    for(int i=1;i<=row;i++) {
            if(dp[i][1]==INT_MAX) ok=false;
            dp[i][1] = ok?1:INT_MAX;
    }


    for(int i=2;i<=row;i++){
        for(int j=2;j<=col;j++){
            if(dp[i][j]==INT_MAX) continue;
            if(dp[i-1][j]==INT_MAX && dp[i][j-1]==INT_MAX)
                dp[i][j]=INT_MAX;
            else if(dp[i-1][j]==INT_MAX)
                dp[i][j]=dp[i][j-1];
            else if(dp[i][j-1]==INT_MAX)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;

        }
    }

    cout<<(dp[row][col]==INT_MAX?0:dp[row][col])<<endl;
}
*/

//https://www.spoj.com/problems/MST1/
#include<iostream>
#include<algorithm>
using namespace std;

int dp[20000001];
int mxN = 2e7;

int main(){

    dp[0]=0;dp[1]=0;

    for(int i=2;i<=mxN;i++){

        if(i%2==0 && i%3==0)
            dp[i]=min({dp[i-1],dp[i/2],dp[i/3]})+1;
        else if (i%2!=0 && i%3!=0)
            dp[i]=dp[i-1]+1;
        else if(i%2==0)
            dp[i]=min(dp[i-1],dp[i/2])+1;
        else
            dp[i]=min(dp[i-1],dp[i/3])+1;
    }

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<dp[n]<<endl;
    }


}


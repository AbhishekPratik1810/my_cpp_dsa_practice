//https://hack.codingblocks.com/app/contests/1338/546/problem
#include<bits/stdc++.h>
using namespace std;

long long c1,c2,c3;

long long memo[100001]={};
long long dp[100001] = {};

long long cost(long long n){
    if(n==1)
        return memo[n]=0;
    if(memo[n]) return memo[n];

    if(n%2)         //ODD
        return memo[n] = min(cost(n-1)+c2,cost((n+1)/2)+c1+c3);
    else
        return memo[n] = min(cost(n-1)+c2,cost(n/2)+c1);
}

long long bottomUp(long long n){
    dp[1]=0;
    for(int i=2;i<=n;i++){
        if(i%2)
            dp[i]=min(dp[i-1]+c2,dp[(i+1)/2]+c1+c3);
        else
            dp[i]=min(dp[i-1]+c2,dp[i/2]+c1);
    }
    return dp[n];
}

int main(){
    long long n; cin>>n>>c1>>c2>>c3;
    cout<<bottomUp(n)<<endl;

}

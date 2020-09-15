//https://www.spoj.com/problems/MIXTURES/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

typedef long long ll;

ll sum(int i, int j, vector<ll> &nums){
    ll ans=0;
    for(int idx=i;idx<=j;idx++){
        ans+=nums[idx];
        ans%=100;
    }
    return ans;
}

ll memo[101][101]={};

ll minSmoke(int beg,int end, vector<ll> &nums){
    if(beg>=end)
        return 0;
    if(memo[beg][end]) return memo[beg][end];

    memo[beg][end]=INT_MAX;
    for(int k=beg;k<end;k++)
        memo[beg][end]=min(memo[beg][end],minSmoke(beg,k,nums)+minSmoke(k+1,end,nums) + sum(beg,k,nums)*sum(k+1,end,nums));

    return memo[beg][end];
}

ll minSmoke(vector<ll> nums,int n){

    vector<ll> prefixSum(n+1);
    prefixSum[1]=nums[0]; prefixSum[0]=0;
    for(int i=2;i<=n;i++) prefixSum[i]=prefixSum[i-1]+nums[i-1];

    ll dp[101][101]={0};

    for(int diff=1;diff<n;diff++){
        for(int j=diff+1;j<=n;j++){
            int i=j-diff;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                ll intermediate = dp[i][k] + dp[k+1][j] + (((prefixSum[k]-prefixSum[i-1])%100)*((prefixSum[j]-prefixSum[k])%100));
                dp[i][j]=min(dp[i][j],intermediate);
            }
        }
    }

    return dp[1][n];

}

int main(){
//    int n
//    while(cin>>n){
        int n;cin>>n;
        vector<ll> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        cout<<minSmoke(nums,n)<<endl;
        cout<<minSmoke(0,n-1,nums)<<endl;
//    }
}

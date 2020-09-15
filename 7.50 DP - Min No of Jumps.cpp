//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
#include<iostream>
#include<climits>
using namespace std;

int n;

static int dp[10000001];

int minJumps(int currIdx, int jumps[]){

    if(jumps[currIdx]+currIdx>=n) return 1;

    if(dp[currIdx]) return dp[currIdx];

    int val=INT_MAX;

    for(int i=currIdx+1;i<=n && i<=currIdx+jumps[currIdx];i++)
        val=min(val,minJumps(i,jumps));

    if(val==INT_MAX)
        return dp[currIdx] = INT_MAX;

    return dp[currIdx] = 1+val;

}

int main(){
    int t;cin>>t;
    while(t--){
        cin>>n;
        int* jumps = new int[n+1];
        for(int i=1;i<=n;i++)
            cin>>jumps[i];

        for(int i=0;i<=n;i++) dp[i]=0;

        int ans = minJumps(1,jumps);

        if(ans!=INT_MAX) cout<<ans<<endl;
        else cout<<-1<<endl;

    }
}

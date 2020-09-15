//https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1

#include<iostream>
#include<vector>
using namespace std;


int dp[101][101];
int maxProfit(int beg,int end, vector<int> &nums){

    if(beg==end)
        return nums[beg];

    if(dp[beg][end]) return dp[beg][end];

    int currentTotal = 0;
    for(int i=beg;i<=end;i++) currentTotal+=nums[i];

    int firstPicked = currentTotal-maxProfit(beg+1,end,nums);       //Profit if first element is picked
    int lastPicked  = currentTotal-maxProfit(beg,end-1,nums);       //Profit if second element is picked

    return dp[beg][end] = max(firstPicked,lastPicked);

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> nums(n+1);
        for(int i=1;i<=n;i++) cin>>nums[i];     //1 based indexing
        for(int i=0;i<=100;i++)
        for(int j=0;j<=100;j++)
            dp[i][j]=0;
        cout<<maxProfit(1,n,nums)<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
     int n = nums.size();
     int* dp = new int[n];                                //dp[i] = max subarray sum, including nums[i]
     dp[0]=nums[0];
     int ans=dp[0];
     for(int i=1;i<n;i++){
        if(dp[i-1]>0)
            dp[i]=dp[i-1]+nums[i];
        else
            dp[i]=nums[i];
        ans=max(ans,dp[i]);
     }
     return ans;
}

int kadanes(vector<int> &nums){
    int maxSoFar=INT_MIN,currentSum=0;
        for(int i=0;i<nums.size();i++){
            if(currentSum<0)
                currentSum=0;
            currentSum+=nums[i];
            maxSoFar=max(maxSoFar,currentSum);
        }
    return maxSoFar;
}

int main(){
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    cout<<maxSubArray(nums)<<endl;
    cout<<kadanes(nums)<<endl;
}

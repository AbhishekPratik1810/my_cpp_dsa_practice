//https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k/0
//https://leetcode.com/problems/subarray-product-less-than-k/submissions/

#include<iostream>
#include<vector>

using namespace std;

#define ll long long


ll elegantSlidingWindow(vector<ll> &nums, int n,ll k){

    int windowLeft=0;
    ll pdt=1,count=0;

    for(int windowRight=0;windowRight<n;windowRight++){

        pdt*=nums[windowRight];

        while(windowLeft<=windowRight && pdt>=k)
            pdt/=nums[windowLeft++];

        count+=(windowRight-windowLeft+1);

    }

    return count;

}


int main(){

    int t; cin>>t;

    while(t--){

        int n;
        ll k;  cin>>n>>k;

        vector<ll> nums(n);
        for(int i=0;i<n;i++)
            cin>>nums[i];

        cout<<elegantSlidingWindow(nums,n,k)<<endl;


    }


}

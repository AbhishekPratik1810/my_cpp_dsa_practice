//https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum/0

#include <iostream>
using namespace std;

#define ll long long
ll mxN = 1e13;
ll mnN = -1e13;
int main() {
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    ll arr[n];

	    for(int i=0;i<n;i++)
	        cin>>arr[i];

	    ll maxSum = mnN, minSum = mxN, currMax=0, currMin = 0,totalSum=0;

	    for(int i=0;i<n;i++){
	        currMax+=arr[i];
	        currMin+=arr[i];
	        totalSum+=arr[i];
	        maxSum = max(maxSum,currMax);
	        minSum = min(minSum,currMin);
	        if(currMax<0) currMax=0;
	        if(currMin>0) currMin = 0;
	    }

	    if(totalSum==minSum)
	        cout<<maxSum<<endl;
	    else
	        cout<<max(maxSum,totalSum-minSum)<<endl;


	}
	return 0;
}

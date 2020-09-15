//https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array/0
//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/

#include <iostream>
#include <climits>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
	    int ans=INT_MAX;
	    int start = 0, end = n-1;
	    while(start<=end){
	        int mid = start + (end-start)/2;
	        if(arr[mid]>arr[end])
	            start = mid+1;
	        else{
	            ans = min(ans,arr[mid]);        //This is really important, consider 4 5 1 2 3
	            end = mid-1;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}

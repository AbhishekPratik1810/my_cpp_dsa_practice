//https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k/0

#include <iostream>
#include <map>
using namespace std;

int main() {
	int t;
	cin>>t;

	while (t--){

	    int n,k;
	    cin>>n>>k;
	    int arr[n];

	    for(int i=0;i<n;i++)
	        cin>>arr[i];

	    map<int,int> pos;
	    pos[0]=0;

	    int ans=0,cSum=0;

	    for(int i=1;i<=n;i++){

	        cSum+=arr[i-1];
	        if(cSum==k || pos[cSum-k])
	            ans = max(ans,i-pos[cSum-k]);
	        if(!(pos[cSum]))
	            pos[cSum] = i;

	    }

	    cout<<ans<<endl;

	}
	return 0;
}

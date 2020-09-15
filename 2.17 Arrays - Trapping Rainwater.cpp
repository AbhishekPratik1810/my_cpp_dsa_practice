//https://practice.geeksforgeeks.org/problems/trapping-rain-water/0
#include <iostream>
using namespace std;

#define ll long long

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    ll arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    ll maxLeft = arr[0];
	    ll maxRight = arr[n-1];

	    ll barrier[n];

	    for(int i=1;i<=n-2;i++){
	        maxLeft = max(maxLeft,arr[i]);
	        barrier[i] = maxLeft;
	    }

	    for(int i=n-2;i>=1;i--){
	        maxRight = max(maxRight,arr[i]);
	        barrier[i]=min(barrier[i],maxRight);
	    }

	    ll ans=0;

	    for(int i=1;i<=n-2;i++)
	        ans+= barrier[i]-arr[i];


	   cout<<ans<<endl;



	}
	return 0;
}

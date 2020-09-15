//https://practice.geeksforgeeks.org/problems/zero-sum-subarrays/0
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];

	    unordered_map<int,int> count;     //maps the sum -> number of indices where this sum occured    //map is way slower for larger data

	    count[0]=1;

	    int currentSum=0;
	    long long ans=0;
	    for(int i=0;i<n;i++){
	        currentSum+=arr[i];
	        ans += count[currentSum];
	        count[currentSum]++;
	    }

	    cout<<ans<<endl;

	}
	return 0;
}

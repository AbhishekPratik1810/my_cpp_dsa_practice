//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0/
#include <iostream>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int* arr = new int[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
	    int arr2[3]={};

	    for(int i=0;i<n;i++)
	        arr2[arr[i]]++;
	    for(int i=0;i<3;i++){
	        for(int j=0;j<arr2[i];j++)
	            cout<<i<<" ";
	    }
	    cout<<endl;

    }
	return 0;
}

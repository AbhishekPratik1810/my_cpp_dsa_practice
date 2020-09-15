//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0


#include <iostream>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int* arr = new int[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

	    int z=0,o=0,t=n-1;          //zero,ones,twos

	    while(o<=t){                            //Sort zeros and twos using 1s, the 1s will fall into place automatically
	        if(arr[o]==0)
	            swap(arr[o++],arr[z++]);
	        else if (arr[o]==1)
	            o++;
	        else
	            swap(arr[t--],arr[o]);

	    }

	    for(int i=0;i<n;i++)
	        cout<<arr[i]<<" ";
	    cout<<endl;


    }
	return 0;
}

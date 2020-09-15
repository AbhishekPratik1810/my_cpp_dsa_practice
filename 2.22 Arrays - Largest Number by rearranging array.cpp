//https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array/0
#include<iostream>
#include<algorithm>
using namespace std;

bool comparator(string &a, string &b){
    string res1 = a+b;
    string res2 = b+a;
    return stol(res1)>stol(res2);
}


int main() {
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		string arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n,comparator);
		for(int i=0;i<=n-1;i++)
			cout<<arr[i];
		cout<<endl;
	}
	return 0;
}

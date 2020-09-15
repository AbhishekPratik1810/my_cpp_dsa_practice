//https://practice.geeksforgeeks.org/problems/stock-span-problem/0
//mere se jitne bhi chote hai, ya barabar hai, use delete karna hai
//find first which is greater than me
#include <iostream>
#include<stack>
using namespace std;

//DUH
void withoutPair(int arr[], int n){

    stack<int> stocks;
    stocks.push(0);
    cout<<1<<" ";
    for(int i=1;i<n;i++){

        while(!stocks.empty() && arr[stocks.top()]<=arr[i])
            stocks.pop();
        if(stocks.empty())
            cout<<i+1<<" ";
        else
            cout<<i-stocks.top()<<" ";
        stocks.push(i);

    }
    cout<<endl;

}


void efficient(int arr[], int n){

    stack<pair<int,int>> stocks;
    stocks.push({arr[0],0});
    cout<<1<<" ";
    for(int i=1;i<n;i++){

        while(!stocks.empty() && stocks.top().first<=arr[i])
            stocks.pop();
        if(stocks.empty())
            cout<<i+1<<" ";
        else
            cout<<i-stocks.top().second<<" ";
        stocks.push({arr[i],i});

    }
    cout<<endl;

}


//O(n^2)
void inefficient(int arr[], int n){

    for(int i=0;i<n;i++){
        int curr=1,j=i-1;
        while(j>=0){
            if(arr[j--]<=arr[i])
                curr++;
            else
                break;
        }
        cout<<curr<<" ";
    }
    cout<<endl;
}

int main() {
	int t; cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];

	    inefficient(arr,n);
	    efficient(arr,n);
	}
	return 0;
}

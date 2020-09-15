//https://practice.geeksforgeeks.org/problems/next-larger-element/0

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define ll long long

void solve(vector<ll> &nearestGreater, int n, ll arr[]){

    stack<ll> st;

    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            st.push(arr[i]);
            nearestGreater[i]=-1;
        }else{

            while(!st.empty() && st.top()<=arr[i])              //At any point, if I find an element lesser than me, then delete it, as it won't contribute for nearest greater of upcoming elements
                st.pop();                                       //Something bigger has come which can now take place as the nearest greater

            if(st.empty())
                nearestGreater[i]=-1;
            else
                nearestGreater[i] = st.top();

            st.push(arr[i]);

        }
    }

}

int main() {

	int t; cin>>t;

	while(t--){

	    int n; cin>>n;
	    ll arr[n];

	    for(int i=0;i<n;i++)
	        cin>>arr[i];

	    vector<ll> nearestGreater(n);

	    solve(nearestGreater,n,arr);

	    for(auto i : nearestGreater)
	        cout<<i<<" ";

	    cout<<endl;

	}
	return 0;
}

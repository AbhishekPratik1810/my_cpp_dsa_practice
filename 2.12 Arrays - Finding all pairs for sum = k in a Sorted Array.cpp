#include <bits/stdc++.h>
using namespace std;
#define ll long long int


//WCT = O(n)
void solve(){

    //Assuming No Duplicates, ELSE USE 2.11 Hashing Algorithm

    ll n,k,pair=0;
    cin>>n>>k;
    ll* arr = new ll[n];

    for(ll i=0;i<n;i++) cin>>arr[i];

    sort(arr,arr+n);

    ll i=0,j=n-1;

    while(i<j){
        if(arr[i]+arr[j]==k){pair++;i++;j--;}
        else if(arr[i]+arr[j]>k){j--;}
        else i++;
    }

    cout<<pair<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}

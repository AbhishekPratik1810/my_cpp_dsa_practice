#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//Lesser Lines of Code, But Higher WCT = O(n^2)
void solve2(){
    int n,k,pair=0;
    cin>>n>>k;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            {if(arr[i]+arr[j]==k) pair++;}
    }
	    cout<<pair<<endl;
}
//Longer Lines of Code, But Shorter WCT = O(n)
void solve(){
    ll n,k;
    cin>>n>>k;
    ll* arr = new ll[n];
    ll max=0,min;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>max)
            max=arr[i];
        if(i==0)
            min=arr[0];
        else if(arr[i]<min)
            min=arr[i];
    }
    ll* bitset = new ll[max-min+1];
    for(ll i=0;i<(max-min+1);i++){
        bitset[i]=0;
    }


    for(ll i=0;i<(max-min+1);i++){
        if(bitset[i]!=-1){
            if(k == 2*(i+min)){
                pair+=(bitset[i]*(bitset[i]-1))/2 ;
                bitset[i]=-1;
            }else if(k-i-min-min>=0){
                if(bitset[k-i-min-min]!=-1){
                    pair+=(bitset[i]*bitset[k-i-min-min]);
                    bitset[k-i-min-min]=-1;
                }
            }
        }
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

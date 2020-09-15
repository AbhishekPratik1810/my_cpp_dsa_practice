//To print number of elements in intersection of 2 arrays
//WC Time Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define el "\n"
typedef pair<ll,ll> ipair;

/*ll power(int a, int b){
    return (ll)(pow(a,b)+0.5);
}*/
void solve(){
    int n,m;
    cin>>n>>m;
    int* arr1 = new int[n];
    int* arr2 = new int[m];
    int max=0,min;
    for(int i=0;i<n;i++){
        cin>>arr1[i];
        if(i==0)
            min=arr1[i];
        if(arr1[i]>max)
            max=arr1[i];
        if(arr1[i]<min)
            min=arr1[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
        if(arr2[i]>max)
            max=arr2[i];
        if(arr2[i]<min)
            min=arr2[i];
    }

    int* bitset = new int[max-min+1];
    for(int i=0;i<(max-min+1);i++)
        bitset[i]=-1;
    for(int i=0;i<n;i++)
        bitset[arr1[i]-min]=arr1[i];
    int intersection =0;
    for(int i=0;i<m;i++){
        if(bitset[arr2[i]-min]!=-1){
            intersection++;
            bitset[arr2[i]-min]=-1; //For uniqueness of intersection, this means that particular element has been added to intersection successfully, don't count it again
        }

    }

    cout<<intersection<<endl;

}





int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }


	return 0;
}



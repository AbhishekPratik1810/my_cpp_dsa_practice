#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define clear cin.clear();cin.ignore(numeric_limits<streamsize>::max(), '\n');
//INT_MAX         2,147,483,647                       <10^10
//U_INT_MAX       4,294,967,295                       <10^10
//LONG_LONG_MAX   9,223,372,036,854,775,807           <10^18
//U_LONG_LONG_MAX 18,446,744,073,709,551,615          <10^18

/*ll power(int a, int b){
    return (ll)(pow(a,b)+0.5);
}*/

ll* gA(int n){                    //getArray
    ll* arr = new ll[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    return arr;
}

void solve(){
    //https://www.geeksforgeeks.org/find-element-appears-array-every-element-appears-twice/
    int n;
    cin>>n;
    ll* arr = gA(n);

    ll ans=0;
    for(int i=0;i<n;i++){
        ans^=arr[i];
    }
    cout<<ans<<endl;

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



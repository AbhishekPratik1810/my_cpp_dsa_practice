#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define endl "\n"
#define fo for(int i=0;i<n;i++)
#define clear cin.clear();cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define loopSolve int t; cin>>t; while(t--){solve();}
//INT_MAX         2,147,483,647                       <10^10
//U_INT_MAX       4,294,967,295                       <10^10
//LONG_LONG_MAX   9,223,372,036,854,775,807           <10^18
//U_LONG_LONG_MAX 18,446,744,073,709,551,615          <10^18
/*ll power(int a, int b){
    return (ll)(pow(a,b)+0.5);
}*/

vector<int> gV(int n){
    vector<int> v;
    int input;
    fo { cin>>input; v.pb(input); }
    return v;
}

int* gA(int n){
    int* arr = new int[n];
    fo cin>>arr[i];
    return arr;
}


//O(N)|O(1)
void solve(){
    int n,N; cin>>n>>N;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int setBits[32]={};

    for(int i=0;i<n;i++){
        int t = arr[i], idx=0;
        while(t){
            if(t&1){
                setBits[idx]++;
            }
            t>>=1;
            idx++;
        }
    }
    int ans=0;
    for(int i=31;i>=0;i--)
        if(setBits[i]%N)
            ans|=(1<<i);


    cout<<ans<<endl;
}

/*
10 3
12 1 12 3 12 1 1 2 3 3
*/


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    //loopSolve;

	return 0;
}

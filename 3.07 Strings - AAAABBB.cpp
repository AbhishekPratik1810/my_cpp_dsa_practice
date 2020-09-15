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
//ll power(int a, int b){
//    return (ll)(pow(a,b)+0.5);
//}

vector<int> gV(int n){
    vector<int> v(n);
    fo { cin>>v[i];  }
    return v;
}

int* gA(int n){
    int* arr = new int[n];
    fo cin>>arr[i];
    return arr;
}


//https://www.hackerrank.com/contests/bppc11/challenges/aaaaabbbbbbb-string/problem
void solve(){
    int n; cin>>n;
    string s;cin>>s;
    int* suffix = new int[n+2];
    int* prefix = new int[n+1];
    prefix[0]=0;suffix[n+1]=0;

    for(int i=1;i<=n;i++) {if(s[i-1]=='A') prefix[i]=prefix[i-1]+1 ; else prefix[i]=prefix[i-1];}
    for(int i=n;i>=1;i--) {if(s[i-1]=='B') suffix[i]=suffix[i+1]+1; else suffix[i] = suffix[i+1];}

    int ans=INT_MAX;
    for(int i=1;i<=n;i++) ans=min(ans,n-prefix[i]-suffix[i]);
    cout<<ans<<endl;

}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

//    solve();
    loopSolve;
	return 0;
}

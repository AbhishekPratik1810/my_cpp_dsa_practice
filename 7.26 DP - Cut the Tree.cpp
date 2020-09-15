#include <bits/stdc++.h>
#include<fstream>
using namespace std;
#define endl "\n"
#define fo for(int i=0;i<n;i++)
#define clear cin.clear();cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define loopSolve int t; cin>>t; while(t--){solve();}
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ifstream fin;
ofstream fout;
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

//https://www.facebook.com/codingcompetitions/hacker-cup/2020/qualification-round/problems/C
void solve(){
    ll n;fin>>n;

    vector<pair<ll,ll>> forest(n);

    fo fin>>forest[i].first>>forest[i].second;
    map<ll,ll> dp;
    sort(forest.begin(),forest.end());

    ll ans=0;
    for(auto tree: forest){
        ll x=tree.first, h=tree.second;
        dp[x+h]=max(dp[x+h],dp[x]+h);
        dp[x]=max(dp[x],dp[x-h]+h);
        ans=max(ans,max(dp[x],dp[x+h]));
    }


    fout<<ans<<endl;


}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    fin.open("7.26 DP - Input.txt");
    fout.open("7.26 DP - Output.txt");
    int t;
    fin>>t;
    int ctr=1;
    while(t--){
        fout<<"Case #"<<ctr<<": ";
        solve();
        ctr++;
    }


	return 0;
}

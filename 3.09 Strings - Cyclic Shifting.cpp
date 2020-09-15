#include <bits/stdc++.h>
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

//https://codeforces.com/contest/1389/problem/C
void solve(){
    string s;
    cin>>s;

    map<int,ll> mp;
    ll ans=INT_MIN;
    for(int i=0;i<s.length();i++){
        mp[s[i]-'0']++;
        ans=max(ans,mp[s[i]-'0']);
    }

    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            bool first=true;
            ll count=0;
            for(auto ch:s){
                if(first&& (ch-'0')==i){
                    count++;
                    first=false;
                }else if(!first && (ch-'0')==j){
                    count++;
                    first=true;
                }
            }
            if(!first) count--;
            ans=max(ans,count);
        }

    }
    cout<<(s.length()-ans)<<endl;

}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //solve();
    loopSolve;

	return 0;
}

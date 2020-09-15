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

ll nax = 1000000007;

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

void solve(){
    string s;cin>>s;
    ll n=s.length();
    vector<vector<ll>> dp(n+1,vector<ll> (13,0));                       //(10*rem + dig)%13
                                                                        //dp[i][j] = count of remainder 'j' considering till string of length i

    if(s[0]=='?'){for(int i=0;i<=9;i++) dp[1][i]=1;}
    else dp[1][s[0]-'0']=1;

    //Agar mere paas rem 4 hai, toh main koi naya dig laun, toh rem 'j' kitne baar aata hai

    vector<vector<ll>> magic(13,vector<ll>(13,0));

    for(int i=0;i<=12;i++){
            for(int dig=0;dig<=9;dig++){
                ll val = (10*i+dig)%13;
                magic[i][val]++;
            }
    }

    for(int i=2;i<=n;i++){
        if(s[i-1]=='?'){
            for(int rem=0;rem<=12;rem++){
                ll prevCount=dp[i-1][rem];
                for(int r2=0;r2<=12;r2++)
                    dp[i][r2]= (dp[i][r2]+(prevCount*magic[rem][r2])%nax)%nax;

            }
        }else{
            for(int rem=0;rem<=12;rem++){
                ll prevCount=dp[i-1][rem]%nax; int dig = s[i-1]-'0';
                ll val = (10*rem+dig)%13;
                dp[i][val]=(dp[i][val]+prevCount)%nax;
            }
        }

    }

    cout<<dp[n][5]<<endl;

}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    //loopSolve;

	return 0;
}

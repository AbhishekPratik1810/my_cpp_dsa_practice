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

int getBits(ll num){
	return (int)log2(num) + 1;
}

vector<int> gV(int n){
    vector<int> v;
    int input;
    fo { cin>>input; v.pb(input); }
    return v;
}

ll* gA(int n){
    ll* arr = new ll[n];
    fo cin>>arr[i];
    return arr;
}

ll MAX = 1e9+7;

void solve(){
    int n,c;
    cin>>n;
    ll* wt = gA(n);
    cin>>c;

//    ll** dp= new ll*[n+1];
//    for(int i=0;i<n+1;i++) dp[i]=new ll[c+1];
    vector<int> temp(c+1);
    vector<vector<int>> dp(n+1,temp);

    for(int j=1;j<c+1;j++) dp[0][j]=0;
    for(int i=0;i<n+1;i++) dp[i][0]=1;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<c+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]= (dp[i-1][j-wt[i-1]]%MAX + dp[i-1][j]%MAX)%MAX;
            }else{
                dp[i][j]=dp[i-1][j]%MAX;
            }
        }
    }

    cout<<dp[n][c]<<endl;

//    delete dp;
//    dp = NULL;

}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //solve();
    loopSolve;

	return 0;
}

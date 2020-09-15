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

static ll dp[1001][10001];

//https://www.hackerrank.com/contests/bppc13/challenges/another-oops-online-assignment
void solve(){
    int c,n;
    cin>>c>>n;
    int* wt = new int[n]; int* val = new int[n];
    int max1=INT_MIN;
    fo{
        cin>>wt[i]; cin>>val[i];
        max1=max(max1,val[i]);
    }

    for(int i=0;i<=10000;i++)
        dp[0][i]=INT_MAX-max1;

    for(int i=0;i<=n;i++)
        dp[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=10000;j++){
            if(wt[i-1]<=j){
                dp[i][j]= min(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]=min((ll)val[i-1],dp[i-1][j]);
            }
        }
    }
    if(dp[n][c]==INT_MAX-max1){
        int i=c;
        while(i<=1e4 && dp[n][c]==INT_MAX-max1){
            dp[n][c]=min(dp[n][c],dp[n][++i]);
        }
    }
    cout<<dp[n][c]<<endl;

}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();

	return 0;
}

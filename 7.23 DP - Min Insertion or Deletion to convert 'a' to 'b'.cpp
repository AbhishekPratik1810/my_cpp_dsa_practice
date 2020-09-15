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

int* gA(int n){
    int* arr = new int[n];
    fo cin>>arr[i];
    return arr;
}


//https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions/0
//x se LCS(x,y) pe pahuncho via x-LCS(x,y) deletion in x. Then LCS se y pe pahuncho by y-LCS(x,y) insertions. Total operations = x-LCS(x,y)+ y-LCS(x,y) = x+y - 2*LCS(x,y)
void solve(){
    int n,m; cin>>n>>m;
    string x,y; cin>>x>>y;

    static int dp[1001][1001];
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++)
            dp[i][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout<<n+m-(2*dp[n][m])<<endl;

}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //solve();

    loopSolve;


	return 0;
}

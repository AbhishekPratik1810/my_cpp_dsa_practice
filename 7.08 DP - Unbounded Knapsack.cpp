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

int dp[1001][1001];

// 0.03s
void solve(){
    int n,c;
    cin>>n>>c;
    int* val=gA(n);
    int* wt=gA(n);

    memset(dp,0,sizeof(dp));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<c+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]= max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
            }else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }
    cout<<dp[n][c]<<endl;
}

void reducedSpaceComplexity(){
    int n,c; cin>>n>>c;
	int* wt = new int[n];
	int* val = new int[n];

	for(int i=0;i<n;i++) cin>>wt[i];
	for(int i=0;i<n;i++) cin>>val[i];

	vector<int> dp(c+1,0);

	for(int i=0;i<=n;i++)
		for(int cap=1;cap<=c;cap++)
			if(wt[i]<=cap)
				dp[cap]= max(val[i]+dp[cap-wt[i]],dp[cap]);


	cout<<dp[c]<<endl;

	delete[] wt; delete[] val;
	wt=NULL,val=NULL;
}

int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //solve();
    loopSolve;

	return 0;
}

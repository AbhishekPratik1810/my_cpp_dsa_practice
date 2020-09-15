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

//To partition a set into 2 subsets such that the difference of the partition's sum is k. Then find the count of how many such partitions made
//For example wt[] = {1,1,2,3} can be partitioned into {{1,3},{1,2}};{{1,1,2},{3}};{{1,3},{1,2}} Note that it is assumed that the 2 1's are different

void solve(){
    int n,diff,c,sum=0;           //c=s1 here
    cin>>n>>diff;
    int* wt = gA(n);
    fo sum+=wt[i];
    //cout<<sum<<endl;
    c=(sum+diff)/2;

    //#Now a code for All subsets with a given sum
    vector<int> col(c+1,0);
    vector<vector<int>> dp(n+1,col);
    for(int i=0;i<=n;i++) dp[i][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++){
            if(wt[i-1]<=j){
                    dp[i][j]=dp[i-1][j-wt[i-1]]+dp[i-1][j];
            }else{
                    dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][c]<<endl;
}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    //loopSolve;

	return 0;
}

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


int coinChange(vector<int>& wt, int amount) {
        int n=wt.size(),c=amount;
        vector<int> col(c+1,INT_MIN);
        vector<vector<int>> dp(n+1,col);
        for(int i=0;i<n+1;i++) dp[i][0]=0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<c+1;j++){
                if(wt[i-1]<=j){
                   dp[i][j]=max(dp[i][j-wt[i-1]]+1, dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

       return dp[n][c]==INT_MIN ? -1:dp[n][c];
}



int ways(int end, vector<int> &wt, int amount, vector<vector<int>> &dp){

        if(amount==0)
            return 1;

        if(end==0)
            return 0;

        if(dp[amount][end]!=-1) return dp[amount][end];

        if(wt[end-1]>amount)
            return dp[amount][end] = ways(end-1,wt,amount,dp);

        else
            return dp[amount][end] = ways(end,wt,amount-wt[end-1],dp) + ways(end-1,wt,amount,dp);



}

int change(int amount, vector<int>& wt) {

        int  n = wt.size();

        vector<vector<int>> dp(amount+1, vector<int> (n+1,-1));         //If the answer can be 0, then always initialize with -1

        return ways(n,wt,amount,dp);

}

int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    vector<int> testCase = {29,3,4};
    int amount = 19;
    cout<<coinChange(testCase,amount)<<endl;

    //solve();
    //loopSolve;

	return 0;
}

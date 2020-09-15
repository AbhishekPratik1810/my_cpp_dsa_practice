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

int elegantCoinChange(vector<int>& wt, int amount){
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < wt.size(); j++) {
                if (wt[j] <= i) {
                    dp[i] = min(dp[i], dp[i - wt[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
}


// 172ms | 46MB     0.37s
int coinChange(vector<int>& wt, int amount) {
        int n=wt.size(),c=amount;
        vector<int> col(c+1,amount+1);
        vector<vector<int>> dp(n+1,col);
        for(int i=0;i<n+1;i++) dp[i][0]=0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<c+1;j++){
                if(wt[i-1]<=j){
                   dp[i][j]=min(dp[i][j-wt[i-1]]+1, dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

       return dp[n][c]>amount ? -1 : dp[n][c];
}

int printCoins(vector<int> wt,int amount){
    int n=wt.size(),c=amount;
    sort(wt.begin(),wt.end()); //if output is desired from maximum to minimum coin denomination
    vector<int> col(c+1,amount+1);
    vector<vector<int>> dp(n+1,col);

    for(int i=0;i<=n;i++) dp[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++){
            wt[i-1]<=j ? dp[i][j]=min(1+dp[i][j-wt[i-1]],dp[i-1][j]) : dp[i][j]=dp[i-1][j];
        }
    }

    if(dp[n][c]>amount)
        return -1;
    else{
        int i=n,j=c;
        while(j!=0){
            if(dp[i][j]==dp[i-1][j])i--;
            else{
                cout<<wt[i-1]<<" ";
                j-=wt[i-1];
            }
        }
        cout<<endl;
        return dp[n][c];
    }

}
int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    vector<int> testCase = {186,419,83,408};
    int amount = 6249;
    cout<<coinChange(testCase,amount)<<endl;
    cout<<printCoins(testCase,amount)<<endl;
    //solve();
    //loopSolve;

	return 0;
}

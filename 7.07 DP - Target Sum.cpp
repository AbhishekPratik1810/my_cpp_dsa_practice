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


//https://leetcode.com/problems/target-sum/
// O(nc)| O(nc)     8 ms | 12.5 MB
int findTargetSumWays(vector<int>& wt, int diff) {
    int n=wt.size(),sum,c;
    sum=accumulate(wt.begin(),wt.end(),0);

    if(diff>1000) return 0;

    if((sum+diff)%2!=0) return 0;

    c=(sum+diff)/2;


    vector<int> col(c+1,0);
    vector<vector<int>> dp(n+1,col);

    dp[0][0]=1;

    int nZ=0;
    for(int i=1;i<n+1;i++){
        if(wt[i-1]==0)
            dp[i][0]=(1<<(++nZ));
        else
            dp[i][0]=dp[i-1][0];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++){
            if(wt[i-1]<=j){
                dp[i][j]=dp[i-1][j-wt[i-1]]+dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][c];

}
int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    vector<int> testCase = {0,1};
    vector<int> testCase2 = {25,29,23,21,45,36,16,35,13,39,44,15,16,14,45,23,50,43,9,15};
    int targetSum = 1;
    int targetSum2 = 32;
    cout<<findTargetSumWays(testCase,targetSum)<<endl;
    cout<<findTargetSumWays(testCase2,targetSum2)<<endl;
    //loopSolve;

	return 0;
}

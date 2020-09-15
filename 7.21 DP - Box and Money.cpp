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


//https://www.hackerrank.com/contests/bppc14/challenges/box-and-money/problem
void solve(){
    int row,col; cin>>row>>col;
    vector<vector<int>> arr(row,vector<int>(col));
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>arr[i][j];


    vector<vector<int>> dp(row+1,vector<int>(col+1,0));
    int ans=0;

    for(int i=1;i<=row;i++){

        pair<int,int> maxm,secondMaxm; maxm.first=INT_MIN ; secondMaxm.first=INT_MIN;    //first stores value,second store the jth position //maxm is max in the row, secondMaxm is secondMax in the row
        for(int j=1;j<=col;j++){
            if(dp[i-1][j]>maxm.first){
                secondMaxm.first=maxm.first;
                secondMaxm.second=maxm.second;
                maxm.first=dp[i-1][j]; maxm.second=j;
            }else if(dp[i-1][j]>secondMaxm.first){
                secondMaxm.first=dp[i-1][j]; secondMaxm.second=j;
            }
        }

        for(int j=1;j<=col;j++){
            if(j==maxm.second)  dp[i][j]=arr[i-1][j-1]+secondMaxm.first;                //That means, that max of previous row is just above current box, hence choose second max from prev row
            else dp[i][j]=arr[i-1][j-1]+maxm.first;

            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //solve();
    loopSolve;

	return 0;
}

#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
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

ll MAX = 1e9+7;
//https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right/0/
void solve(){
    int row,col; cin>>row>>col;
    int dp[101][101];
    for(int i=1;i<=100;i++){
        dp[i][1]=1; dp[1][i]=1;
    }
    for(int i=2;i<=row;i++){
        for(int j=2;j<=col;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MAX;
        }
    }
    cout<<dp[row][col]<<endl;
}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    loopSolve;

	return 0;
}

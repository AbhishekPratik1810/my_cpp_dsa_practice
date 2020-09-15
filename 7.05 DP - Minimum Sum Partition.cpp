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

//  O(nc)|O(nc)   0.65s         (Lauda ka hai ye, kuch bhi matlab)
//  WITH c+1 in the for loops, TLE mila, time >1.44 seconds, LOOKS LIKE MY SOLUTION WAS BETTER
void ghantaBetterSolve(){
    int n,c=0;
    cin>>n;
    int* wt = new int[n];
    fo{
        cin>>wt[i];
        c+=wt[i];
    }

    vector<bool> col(c/2+1,false);
    vector<vector<bool>> dp(n+1,col);

    for(int i=0;i<n+1;i++) dp[i][0]=true;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<c/2+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]=dp[i-1][j-wt[i-1]]||dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    for(int i=c/2;i>=0;i--){
        if(dp[n][i]){
            cout<<c-2*i<<endl;
            return;
        }
    }

}



//c max = 10^4, n max = 50
//JO BHI NEECHE LIKHA HAI, LITE.
/*
    isPossible executes in O(nc)|O(nc)
    solve executes in O(c)
    Hence total Time complexity = O(nc^2) = O(10^9), note however, this also has some flaws, jo samajh nahi aa raha, as for cmax = 10^4, solve will be executed in O(1) because
    j=c/2 pe hi answer aa jayega
*/
//O(nc^2)|O(nc) 0.69 s
bool isPossible(int wt[],int c,int n){

    vector<bool> col(c+1,false);
    vector<vector<bool>> dp(n+1,col);

    for(int i=0;i<=n;i++) dp[i][0]=true;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++){
            if(wt[i-1]<=j){
                dp[i][j]=dp[i-1][j-wt[i-1]]||dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][c];

}


void solve(){
    int n,c=0;
    cin>>n;
    int* wt = gA(n);
    fo{
        c+=wt[i];
    }

    for(int i=c/2;i>=0;i--){

        if(isPossible(wt,i,n)){
           // cout<<"It is possible for c "<<c<<" and i "<<i<<endl;
            cout<<(c-2*i)<<endl;
            break;
        }
    }

}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //solve();
    loopSolve;


	return 0;
}

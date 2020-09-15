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


void oDNMElegant(){
    int n;cin>>n;
    cout<<n/2+1<<endl;
}

//https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter/0
void orderDoesnotMatter(){
    int n;cin>>n;

    static int dp[3][1000001];
    for(int j=0;j<=1e6;j++)
        dp[0][j]=0;
	dp[0][0]=1;dp[1][0]=1;dp[2][0]=1;

	int wt[]={1,2};
	for(int i=1;i<=2;i++){
	    for(int j=1;j<=1e6;j++){
	        if(wt[i-1]<=j){
	            dp[i][j]=dp[i][j-wt[i-1]]+dp[i-1][j];
	        }else{
	            dp[i][j]=dp[i-1][j];
	        }
	    }
	}
	cout<<dp[2][n]<<endl;
}

//https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair/0
void orderMatters(){
    int n;cin>>n;
    ll MAX = 1e9+7;

    int dp[100001];
	dp[1]=1;dp[2]=2;

	for(int i=3;i<=1e5;i++)
	    dp[i]=((dp[i-1]%(MAX))+(dp[i-2]%MAX))%MAX;

	cout<<dp[n]
}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;cin>>t;
    while(t--){
        orderMatters();
    }

	return 0;
}

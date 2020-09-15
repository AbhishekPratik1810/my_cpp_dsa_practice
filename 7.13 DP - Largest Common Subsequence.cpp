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

int memo[101][101];
int dp[101][101];

void printLCS(int l1,int l2,string x,string y){
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int i=l1,j=l2,current=dp[l1][l2];

    vector<char> ans;

    while(current!=0){
        if(dp[i-1][j]==dp[i][j-1]){
            if(dp[i-1][j]==current){        //Don't Select
                i--;                        //Can go in any direction here, if you do j--, then another subsequence will come
            }else{                          //Select as this means, the only other choice is, dp[i][j]=dp[i-1][j-1]+1
                ans.pb(x[i-1]);             //can also do ans.pb(y[j-1]) as both will be same, because this is the case which is when selection happens
                current--;
            }
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;                            //Move Upwards in table
        }else{
            j--;                            //Move Left in table
        }
    }
    reverse(ans.begin(),ans.end());

    for(auto c: ans)
        cout<<c;
    cout<<endl;


    //Approach 2

    i=l1,j=l2,current=dp[l1][l2];
    vector<char> ans2;

    while(current!=0){
        if(x[i-1]==y[j-1]){
            ans2.pb(x[i-1]);i--;j--;current--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }

    }

    reverse(ans2.begin(),ans2.end());

    for(auto c: ans2)
        cout<<c;
    cout<<endl;

}

int dynamicProgramming(int l1,int l2,string x,string y){
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[l1][l2];
}

int recursion(int l1,int l2, string x,string y){
    if(l1==0 || l2==0)
        return 0;
    else{
        if(memo[l1][l2]!=0)
            return memo[l1][l2];

        return x[l1-1]==y[l2-1] ? memo[l1][l2] = 1 + recursion(l1-1,l2-1,x,y) : memo[l1][l2] = max(recursion(l1-1,l2,x,y),recursion(l1,l2-1,x,y));

        /* Above is equivalent to
        if(x[l1-1]==y[l2-1])
            return memo[l1][l2] = 1 + recursion(l1-1,l2-1,x,y);
        else
            return memo[l1][l2] = max(recursion(l1-1,l2,x,y),recursion(l1,l2-1,x,y));
        */

    }

}


void solve(){
    int l1,l2;  cin>>l1>>l2;
    string x,y; cin>>x>>y;
    memset(memo,0,sizeof(memo));
    cout<<recursion(l1,l2,x,y)<<endl;
    cout<<dynamicProgramming(l1,l2,x,y)<<endl;
    printLCS(l1,l2,x,y);


}
/*
76 32
JATAXGPDMYLDXUKDNFTPRRUMBMEMLROWRHWOQNTCLGHLCRORZHGSBAECPLPCCDYVNXMDMFHAOPLQ
IZKHIQBJTIMITDKXIKSXJECWMKWABHSL
*/

int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    //loopSolve;

	return 0;
}

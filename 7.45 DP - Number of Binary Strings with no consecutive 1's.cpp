//https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0

/*
    Better Logic
    The answer is actually fibonacci series, i.e f(n) = f(n-1) + f(n-2);

    The final string obtained, in all these sequences, will either end with a _0, or end with a 01
    How?? well for f(n-1) it is highly obvious that find all binary strings with no consecutive ones, and then add a '0' at the end (this covers the case for _0)

    For strings ending with 01, find all strings of length n-2, without consecutive ones, and simply add '01' to it

    Hence, f(n) = f(n-1) + f(n-2)


*/

#include<iostream>
using namespace std;


int mxN = 1e9+7;

int dp[100001]={};


int val(int n){

    if(n==0)
        return 0;
    if(n==1)
        return 2;
    if(n==2)
        return 3;

    if(dp[n]) return dp[n];

    return dp[n] = (val(n-1)%mxN + val(n-2)%mxN)%mxN;



}



int main(){

    int t; cin>>t;

    while(t--){
        int n;
        cin>>n;
        cout<<val(n)<<endl;
    }


}




/*
#include<iostream>
using namespace std;

long long dp[91][2] ={};                          //dp[n][0/1] count of all non consecutive 1 BS of length n ending with 0/1  For example dp[2][0] = 2 ("10","00") , dp[2][1] = 1 ("01")
int mod = 1e9+7;

long long magic(int n, bool ending){              //count of all non consecutive 1 BS of length 'n' ending with 1/0 based on ending
    if(n==1 && ending) return 1;
    if(n==1 && !ending) return 2;
    if(ending && dp[n][1]) return dp[n][1];
    if(!ending && dp[n][0]) return dp[n][0];
    if(ending==1)
        return dp[n][1] = magic(n-1,0)%mod;
    else
        return dp[n][0] = ((magic(n-1,0)%mod)+(magic(n-1,1)%mod))%mod;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n==1) cout<<2<<endl;
        else cout<<(magic(n-1,1)+magic(n-1,0))%mod<<endl;
    }
}
*/

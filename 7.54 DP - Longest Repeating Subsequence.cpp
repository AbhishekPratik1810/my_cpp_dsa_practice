#include<iostream>
using namespace std;



int dynamicProgramming(int l1,int l2,string x,string y){

    int dp[l1+1][l2+1];
    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++)
            dp[i][j]=0;
    }

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(x[i-1]==y[j-1] && i!=j){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[l1][l2];
}



void solve(){
    int l1; cin>>l1;
    string x; cin>>x;

    cout<<dynamicProgramming(l1,l1,x,x)<<endl;



}


int main() {

	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t; cin>>t;
    while(t--){
        solve();
    }

	return 0;
}

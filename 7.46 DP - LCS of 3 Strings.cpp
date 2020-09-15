/*
Immediate idea that comes to mind is that to get the LCS of 2 strings, and then find LCS of this string with the 3rd one
This will obviously fail as while retracing the LCS of 2 strings, one should remember that LCS of 2 strings need not be unique
Consider x = "abaxyz" y = "xyzaba" z ="xyz"
If while retracing we get LCS(x,y) = "abc" our output will be 0, whereas it should be 3
*/

#include<iostream>
#include<algorithm>
using namespace std;

string x,y,z;

int dp[101][101][101];

int lcsRecursion(int l1,int l2,int l3){

    if(l1==0 || l2==0 || l3==0) return 0;

    if(dp[l1][l2][l3]!=-1) return dp[l1][l2][l3];                                                        //NOTE AS 0 is a valid answer,DON'T INITIALISE DP WITH 0, INITIALIZE WITH -1 AS FOR THE CASES WHERE ANSWER IS INDEED 0, IT WILL CALCULATE AGAIN AND GIVE TLE

    if(x[l1-1]==y[l2-1] && y[l2-1]==z[l3-1]) return dp[l1][l2][l3] = 1+lcsRecursion(l1-1,l2-1,l3-1);

    return dp[l1][l2][l3]=  max({lcsRecursion(l1,l2-1,l3),lcsRecursion(l1-1,l2,l3),lcsRecursion(l1,l2,l3-1)});
}

int bottomUp(int l1,int l2,int l3){

    for(int i=0;i<=l1;i++) dp[i][l2][l3]=0;
    for(int j=0;j<=l2;j++) dp[l1][j][l3]=0;
    for(int k=0;k<=l3;k++) dp[l1][l2][k]=0;

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            for(int k=1;k<=l3;k++){
                if(x[i-1]==y[j-1] && y[j-1]==z[k-1]) dp[i][j][k]=1+dp[i-1][j-1][k-1];
                else dp[i][j][k]=max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
            }
        }
    }

    return dp[l1][l2][l3];
}

int main(){
    int t; cin>>t;
    while(t--){
        int l1,l2,l3; cin>>l1>>l2>>l3;
        cin>>x>>y>>z;
        for(int i=0;i<=l1;i++){
            for(int j=0;j<=l2;j++)
                for(int k=0;k<=l3;k++)
                    dp[i][j][k]=-1;
        }
        cout<<lcsRecursion(l1,l2,l3)<<endl;
        cout<<bottomUp(l1,l2,l3)<<endl;
    }
}


//https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1

#include<iostream>
using namespace std;

bool isMatching(string &pat, string &inp){

    int l1=inp.size(), l2 = pat.size();

    bool dp[l1+1][l2+1];            //Row is inp, Col is pat

    //--Initialization Started--//
    for(int i=1;i<=l1;i++) dp[i][0]=0;
    for(int j=1;j<=l2;j++) dp[0][j]=0;

    int j=1;
    while(j<=l2 && pat[j-1]=='*')
        dp[0][j++]=1;

    dp[0][0]=1;
    //--Initialization Finished--//

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(inp[i-1]==pat[j-1] || pat[j-1]=='?')
                dp[i][j]=dp[i-1][j-1];
            else if(pat[j-1]=='*')
                dp[i][j]=dp[i-1][j]||dp[i][j-1];
            else
                dp[i][j]=0;
        }
    }

    return dp[l1][l2];

}

int main(){

    int t; cin>>t;

    while(t--){

        string pat,inp;
        cin>>pat>>inp;

        cout<<isMatching(pat,inp)<<endl;

    }

}

//https://leetcode.com/problems/distinct-subsequences-ii/discuss/192030/Java-DP-O(N2)-time-greater-O(N)-time-greater-O(1)-space
//https://online.codingblocks.com/app/player/150053/content/153656/5235/code-challenge

/*
Consider s = ABABA
A       B       A  (X)     B  (X)      A  (X)
        AB      AA         AB (X)      AA (X)

                BA         BB          BA (X)
                ABA        ABB         ABA(X)

                           AAB         AAA

                           BAB         BAA
                           ABAB        ABAA

                                       BBA
                                       ABBA

                                       AABA

                                       BABA
                                       ABABA
*/

#include<iostream>
using namespace std;

int mod = 1e9+7;

int uniqueSubsequences(string s){

    int lastOccur[26], n = s.size();

    bool hasOccur[26] = {};



    int curr=0;

    for(int i=0;i<n;i++){
        int unique = curr+1, currChar = s[i]-97;
        if(hasOccur[currChar]){
            unique= (unique + mod - (lastOccur[currChar]))%mod;         //modular subtraction right way. a>b but a%b - b%mod might be -ve which we never want => we add instead of (a-b)%mod, we use (a+mod-b)%mod
            lastOccur[currChar]+=unique;
            lastOccur[currChar]%=mod;
        }else{
            lastOccur[currChar]=unique;
            hasOccur[currChar]=1;
        }
        curr+=unique;
        curr%=mod;
    }

    return curr+1;

}

int main(){

    int t;
    string s;
    cin>>t;
    while(t--){

        cin>>s;
        cout<<uniqueSubsequences(s)<<endl;

    }

}

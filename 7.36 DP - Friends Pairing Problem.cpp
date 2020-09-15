//https://practice.geeksforgeeks.org/problems/friends-pairing-problem/0
//Notice how you will get overflow inspite of dividing by mod if taking int. this is because, during (n-1)*(fpp(n-2)%mod) both might be less than INT_MAX, but their multiplication can overflow
//Example, a<5, b<5 but (a*b)%5 = (25)%5 = (overflow)%5

#include<iostream>
using namespace std;
int mod = 1e9+7;

long long memo[101];

long long fpp(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(memo[n]) return memo[n];
    return memo[n] = (fpp(n-1)%mod+(((n-1)*(fpp(n-2)%mod))%mod))%mod;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i=0;i<=100;i++) memo[i]=0;
        cout<<fpp(n)<<endl;
    }
}

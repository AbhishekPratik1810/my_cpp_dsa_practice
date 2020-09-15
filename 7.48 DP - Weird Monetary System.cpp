// https://www.hackerearth.com/practice/algorithms/dynamic-programming/state-space-reduction/practice-problems/algorithm/bytelandian-gold-coins/submissions/

#include<iostream>
#include<map>
using namespace std;

typedef long long ll;

map<ll,ll> dp;

ll maxGold(ll n){
	if(n<=1)
		return n;
    if(dp[n]) return dp[n];
	ll val1=0,val2=0,val3=0;
	val1 = max(n/2, maxGold(n/2));
	val2 = max(n/3,maxGold(n/3));
	val3 = max(n/4,maxGold(n/4));
	return dp[n] = max(n,val1+val2+val3);
}

int main() {
    ll n;
    while(cin>>n){
	    cout<<maxGold(n)<<endl;
    }

}

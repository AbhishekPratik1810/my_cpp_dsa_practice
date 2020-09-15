//https://codeforces.com/contest/1398/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){

    int l; cin>>l;
    string s;
    cin>>s;

    unordered_map<int,int> count;

    int sum=0;
    ll ans=0;
    count[0]=1;

    for(int i=1;i<=l;i++){
        sum+=s[i-1]-'0';
        sum-=1;
        ans+=count[sum];
        count[sum]++;
    }

    cout<<ans<<endl;
}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t; cin>>t;
    while(t--)
        solve();

	return 0;
}

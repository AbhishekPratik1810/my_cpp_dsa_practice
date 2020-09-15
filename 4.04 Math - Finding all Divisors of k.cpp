    //https://atcoder.jp/contests/abc172/tasks/abc172_d
    #include <bits/stdc++.h>
    using namespace std;

    #define ll long long
    #define ar array

    const int mxN=1e7;
    int n, c[mxN+1];

    int main() {
    	ios::sync_with_stdio(0);
    	cin.tie(0);

    	cin >> n;
    	for(int i=1; i<=n; ++i)
    		for(int j=0; (j+=i)<=n; )
    			++c[j];
    	ll ans=0;
    	for(int i=1; i<=n; ++i)
    		ans+=(ll)i*c[i];
    	cout << ans;
    }

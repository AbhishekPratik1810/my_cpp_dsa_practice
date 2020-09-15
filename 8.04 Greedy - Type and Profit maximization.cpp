#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//https://www.hackerrank.com/contests/bppc19/challenges/activity-and-net-profit/submissions/code/1325508938
int main(){
    int n,m; cin>>n>>m;
    ll t=0;
    vector<pair<ll,ll>> inp;

    for(int i=0;i<n;i++){
        ll type,profit; cin>>type>>profit;
        inp.push_back(make_pair(profit,type));          //profit,type;
    }

    sort(inp.begin(),inp.end(),greater<pair<ll,ll>>());

    vector<bool> taken(n+1,0); vector<int> dup;

    ll ans=0;
    for(int i=0;i<m;i++){
        ans+=inp[i].first;
        if(!taken[inp[i].second]){
            taken[inp[i].second]=1;
            t++;
        }else dup.push_back(i);
    }

    ll orig=ans;
    ans+=(t*t);
    int dupCount=m-t,ctr=0,k=m; int j=dupCount-1;

    for(int i=1;i<=dupCount;i++){
        bool ok=false;
        while(k<n && ctr<i){
            if(!taken[inp[k].second]){
                orig-=inp[dup[j]].first;
                orig+=inp[k].first;
                taken[inp[k].second]=1;
                ctr++; j--;
                ok=true;
            }
            k++;
        }
        if(ok)
            ans=max(ans,orig+(t+i)*(t+i));
    }
    cout<<ans<<endl;

}

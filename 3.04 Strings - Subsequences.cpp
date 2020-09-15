#include <bits/stdc++.h>
using namespace std;

bool comp(string &a, string &b){
    if(a.size()==b.size())
        return a<b;
    return a.size()<b.size();
}

vector<string> subsets(int end, string &s){

    if(end==0)
        return vector<string>(1,"");

    vector<string> curr = subsets(end-1,s);

    int currSize = curr.size();
    for(int i=0;i!=currSize;i++)
        curr.push_back(curr[i]+s[end-1]);


    return curr;



}

void usingRecursion(int n, string &s){

    vector<string> ans =  subsets(n,s);
    sort(ans.begin(),ans.end(),comp);

    for(auto str : ans)
        cout<<str<<" ";
    cout<<endl;
}

void usingBitMasking(int n, string &s){

    cout<<" ";      //for empty subsequence

    for(int i=1;i<(1<<n);i++){
        int t=i,j=0;
        while(t>0){
            (t&1)?(cout<<s[j]):(cout<<"");
            j++;
            t=t>>1;
        }
        cout<<" ";
    }

    cout<<endl;

}



void solve(){

    string s;
    cin>>s;
    int n = s.length();

    usingBitMasking(n,s);

    usingRecursion(n,s);

}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    //loopSolve;

	return 0;
}

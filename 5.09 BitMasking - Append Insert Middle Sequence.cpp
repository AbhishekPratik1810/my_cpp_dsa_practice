#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define pb push_back
#define fo for(int i=0;i<n;i++)
#define clear cin.clear();cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define loopSolve int t; cin>>t; while(t--){solve();}
//INT_MAX         2,147,483,647                       <10^10
//U_INT_MAX       4,294,967,295                       <10^10
//LONG_LONG_MAX   9,223,372,036,854,775,807           <10^18
//U_LONG_LONG_MAX 18,446,744,073,709,551,615          <10^18

/*ll power(int a, int b){
    return (ll)(pow(a,b)+0.5);
}*/

vector<int> gV(int n){
    vector<int> v;
    int input;
    fo { cin>>input; v.pb(input); }
    return v;
}

int* gA(int n){
    int* arr = new int[n];
    fo cin>>arr[i];
    return arr;
}
/*
Idea : The 1st set bit from LSB corresponds to the idx + 1
Example 10001 corresponds to 0 + 1 = 1
10010 Corresponds to 1 + 1 = 2
10100 Corresponds to 2 + 1 = 3
11000 Corresponds to 3 + 1 = 4
10000 Corresponds to 4 + 1 = 5
*/
//https://codeforces.com/problemset/problem/743/B
void solve(){
    ll n,k;
    cin>>n>>k;

    int count =0;
    while(k>0){
        if(k&1==1)break;
        k>>=1;
        count++;
    }
    cout<<count+1<<endl;


}




int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    //loopSolve;

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define endl "\n"
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

int getBits(ll num){
	return (int)log2(num) + 1;
}

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


https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_d
void solve(){
    int n; cin>>n;
    int* prices = gA(n);
    ll profit=1000,low,high;

    for(int i=0;i<n-1;i++){
        if(prices[i]<prices[i+1]){
            low=prices[i];
            while(i<n-1 && prices[i]<prices[i+1])
                i++;
            high=prices[i];
            ll bought=profit/low;                           //Note the stocks may increase exponentially consider 100,200,100,200....n times stocks = 1000*2^(n/2);
            profit-=(bought*low);
            ll sold=bought*high;
            profit+=sold;
        }
    }

    cout<<profit<<endl;
}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    //loopSolve;

	return 0;
}

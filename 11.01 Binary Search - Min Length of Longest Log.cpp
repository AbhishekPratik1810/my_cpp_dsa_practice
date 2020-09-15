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

bool possible(int ans,vector<int> &a,int k){
    for(auto log: a){
        if(log%ans==0)
            k-=(log/ans-1);
        else
            k-=log/ans;
    }
    return k>=0;
}

//https://atcoder.jp/contests/abc174/tasks/abc174_e
void solve(){
    int n,k,mx=INT_MIN;         //most optimized ans, else one can also find answer by taking mx=1e9 = max log size acc to question
    cin>>n>>k;
    vector<int> a(n);
    fo{
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    int min=1;                      //mx denotes that value which is definitely the answer. min denotes that value which is trying to approach that answer
    while(min!=mx){
        int mid=(min+mx)/2;         //Let's see if this answer works
        if(possible(mid,a,k))
            mx=mid;                 //As mid is valid answer, and mid<mx, reduce mx = mid
        else
            min=mid+1;              //Doesn't work, => for all logs <= mid, answer won't work => choose min=mid+1
    }

    cout<<min<<endl;

}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    //loopSolve;

	return 0;
}

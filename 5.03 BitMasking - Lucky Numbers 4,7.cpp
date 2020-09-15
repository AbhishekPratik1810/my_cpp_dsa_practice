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

//Same logic but without using string
void method2(){
    int n;
    cin>>n;
    int l=0,t=n,dig,num=0;

    while(t>0){
        dig=t%10;
        dig==4?(num|=0):(num|=(1<<l));
        t/=10;
        l++;
    }
    cout<<((1<<l)-1)+num<<endl;
}

//https://codeforces.com/contest/535/problem/B
void solve(){
    string s;
    cin>>s;
    int l = s.length();
    int ans=0,num=0;
    for(int i=l-1,j=0;i>=0;i--,j++){
        if(s[i]=='4'){
            num|=0;
        }else{
            num|=(1<<j);
        }
    }
    cout<<((1<<l)-1)+num<<endl;

}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    method2();
    //solve();
    //loopSolve;

	return 0;
}

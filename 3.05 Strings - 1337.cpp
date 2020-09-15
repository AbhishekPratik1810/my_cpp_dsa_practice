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

bool isPalindrome(string s){
    char* comp = new char[s.length()+1];
    for(int i=s.length()-1,j=0;i>=0;i--,j++){
        comp[j]=s[i];
    }
    comp[s.length()]='\0';
    if(s.compare(comp)==0)
        return true;
    else
        return false;
}

ll nC2(int n){
    return n*(n-1)/2;
}

//https://codeforces.com/contest/1202/problem/D
void solve(){
   ll n;
   cin>>n;
   int o=1,t,s=1;
   int m=sqrt(n);

   while(nC2(m)<=n){
        m++;
   }
   m--;

   (m>=2)?t=m:t=2;
   int rem = n-nC2(m);

   for(int i=0;i<o;i++) cout<<'1';
   cout<<"33";
   for(int i=0;i<rem;i++) cout<<'7';
   for(ll i=2;i<t;i++)  cout<<'3';
   for(int i=0;i<s;i++) cout<<'7';
   cout<<endl;

}




int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //solve();
    loopSolve;

	return 0;
}

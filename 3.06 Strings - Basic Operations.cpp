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



void solve(){
    int n;
    cin>>n;
    vector<char> str(n,0); //initialises all elements to 0
    fo{
        str[i]=(i%10)+48;
    }
    string s(str.begin(),str.end()); //or s(str.rbegin(),str.rend()) for reverse copy;
    cout<<s<<endl;

    string s2(str.begin(),str.begin()+n/2);
    cout<<s2<<endl;

    reverse(str.begin(),str.end());
    for(auto c:str){
        cout<<c;
    }
    cout<<endl;


}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    //loopSolve;

	return 0;
}

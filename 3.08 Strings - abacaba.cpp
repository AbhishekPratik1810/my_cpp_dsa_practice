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
//ll power(int a, int b){
//    return (ll)(pow(a,b)+0.5);
//}

vector<int> gV(int n){
    vector<int> v(n);
    fo { cin>>v[i];  }
    return v;
}

int* gA(int n){
    int* arr = new int[n];
    fo cin>>arr[i];
    return arr;
}

bool valid(string s){
    int count =0;
    string comp="abacaba";
    for(int i=0;i<s.length()-6;i++){
        if(s[i]!='a')
            continue;
        bool ok=true;
        for(int j=i;j<7+i;j++){
            if(comp[j-i]!=s[j]){
                ok=false;
                break;
            }
        }
        if(ok)
            count++;
    }
    return count==1;
}

//https://codeforces.com/contest/1379/problem/A
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    string comp="abacaba";

    bool ok;
    for(int i=0;i<n-6;i++){
        //Get all substrings of length 7
        string t=s.substr(i,7);
        ok=true;

        //Is it even possible to make this substring abacaba?
        for(int j=0;j<7;j++){
            if(t[j]!='?' && t[j]!=comp[j]){
                ok=false;
                break;
            }
        }

        if(ok){
            vector<int> ind;        //Stores indices of those ? who have been changed
            for(int j=0;j<7;j++){
                if(t[j]=='?'){
                    s[j+i]=comp[j];
                    ind.pb(j+i);
                }
            }
            if(valid(s)){ok=true; break;}
            else{                               //Redo the changes
                for(auto j : ind)
                    s[j]='?';
                ok=false;
            }
        }
    }

    if(ok){
        for(int i=0;i<n;i++){
            if(s[i]=='?')
                s[i]='z';
        }
        cout<<"Yes"<<endl<<s<<endl;
    }else{
        cout<<"No"<<endl;
    }

}

/*
8
7
abacaba
7
???????
11
aba?abacaba
11
abacaba?aba
15
asdf???f???qwer
11
abacabacaba
2
9
???acabaz
8
?b?c?baz
*/
int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //solve();
    loopSolve;

	return 0;
}

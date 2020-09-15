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
//https://codeforces.com/contest/1384/problem/D
void solve(){
    int n; cin>>n;
    ll* arr = new ll[n];
    fo{
        cin>>arr[i];
    }

    vector<int> bits(32,0);
    fo{
        int t=arr[i],count=0;
        while(t>0){
            if(t&1) bits[count]++;
            t>>=1;
            count++;
        }
    }
    reverse(bits.begin(),bits.end());
    bool draw=true,win=true;
    for(auto i : bits){
        if(i%2!=0){
            draw=false;
            if((i-1)%4!=0){
                if((n-i)%2==0)
                    win=false;
            }
            break;
        }
    }
    if(draw){
        cout<<"DRAW"<<endl;
    }else{
        cout<<(win?"WIN":"LOSE")<<endl;
    }


}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //solve();
    loopSolve;

	return 0;
}

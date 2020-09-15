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


//O(1)|O(1) 4ms | 5.9MB
bool elegantDivisorGame(int N){
    return N%2==0?true:false;
}

//O(N^(3/2))|O(N) 4ms | 5.9MB
bool betterDPDivisorGame(int N){
        bool win[1001];
        memset(win,false,sizeof(win));
        win[1]=false;
        for(int i=2;i<=1000;i++){
            for(int j=1;j<=sqrt(i);j++){
                if(i%j==0 && !(win[i-j]||win[i-(i/j)]) ){
                    win[i]=true;
                    break;
                }
            }
        }
        return win[N];
}

//O(N*N)|O(N) (here NMAX = 1000) 36ms | 5.9 MB
bool divisorGame(int N) {
        bool win[1001];
        memset(win,false,sizeof(win));
        win[1]=false;
        for(int i=2;i<=1000;i++){
            for(int j=1;j<i;j++){
                if(i%j==0 && !win[i-j]){
                    win[i]=true;
                    break;
                }
            }
        }
        return win[N];
}

//https://leetcode.com/problems/divisor-game/
int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cout<<(divisorGame(100)?"Alice" : "Bob")<<endl;
    cout<<(elegantDivisorGame(100)?"Alice" : "Bob")<<endl;
	return 0;
}

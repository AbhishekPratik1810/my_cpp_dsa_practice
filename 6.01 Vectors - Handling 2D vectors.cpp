#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define pb push_back
#define fo for(int i=0;i<n;i++)
#define clear cin.clear();cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define loopSolve int t; cin>>t; while(t--){solve();}
//INT_MAX         2,147,483,647                       <10^10    >10^9
//U_INT_MAX       4,294,967,295                       <10^10    >10^9
//LONG_LONG_MAX   9,223,372,036,854,775,807           <10^19    >10^18
//U_LONG_LONG_MAX 18,446,744,073,709,551,615          <10^20    >10^18

unsigned ll power(int a, int b){
    return (unsigned ll)(pow(a,b)+0.5);
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


int nC2(int n){
    return (n*(n-1))/2;
}
//https://codeforces.com/contest/27/problem/B
void solve(){
    int n,w,l;
    cin>>n;

    map<int,vector<vector<int>>> mp;

    vector<int> temp;
    vector<vector<int>> temp2(2,temp);          //DONT EVER MISS THIS STEP

    map<int,int> participants;

    fo mp[i+1]=temp2;                           //Before pushing back, always initialise your vectors


    for(int i=0;i<nC2(n)-1;i++){
        cin>>w>>l;
        mp[w][0].pb(l);                          //Win over l
        mp[l][1].pb(w);                          //Loss against w
        participants[w]++;
        participants[l]++;
    }

    int p1=1001,p2;
    for(int i=0;i<n;i++){
        if(participants[i+1]<n-1){
            if(p1==1001)
                p1=i+1;
            else{
                p2=i+1;
                break;
            }
        }
    }
    //Checking if someone p1 won over is present in p2's loss list or not. If yes, that means p2 will also defeat p1
    for(int i=0;i<mp[p1][0].size();i++){
        if(find(mp[p2][1].begin(),mp[p2][1].end(),mp[p1][0][i])!=mp[p2][1].end()){
            cout<<p1<<" "<<p2<<endl;
            return;
        }
    }

    cout<<p2<<" "<<p1<<endl;

}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    //loopSolve;

	return 0;
}

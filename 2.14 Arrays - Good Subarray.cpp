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


//https://www.hackerrank.com/contests/bppc11/challenges/good-subarrays-2/problem
void solve(){
    int n; cin>>n;
    int* arr = new int[n];
    int* eoc = new int[n+1];                                        //means that at ith positon of arr, there exist eoc[i] (even-odd) numbers
                                                                    //eoc[i]>0 => more even numbers, eoc[i]<0 => more odd number, eoc[i]=0 => equal odd and even no encountered
    memset(eoc,0,sizeof(*eoc));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<=n;i++){
        if(arr[i-1]%2==0){
            eoc[i]=eoc[i-1]+1;
        }else{
            eoc[i]=eoc[i-1]-1;
        }
    }

    ll count=0;

    //O(n^2)
/*  for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j+=2){
            if(eoc[j]-eoc[i-1]==0)
                count++;
        }
    }
*/
    //O(n)
    map<int,int> mp;
    eoc[0]=0;                                //so that, when eoc[i]=0, then we by default increment the counter, how we do that? by saying that eoc[0] = 0 i.e '0' has already encountered
                                             //Note, counter is incremented when eoc[i]=eoc[j] for i<j; this is achieved using maps
    for(int i=0;i<=n;i++){
        if(mp[eoc[i]]>=1) count+=mp[eoc[i]];
        mp[eoc[i]]++;
    }


    cout<<count<<endl;


}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);



    solve();

    //loopSolve;
	return 0;
}

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
//Involves creating another mask for the individual item and then '&'ing with the first mask to check for common set bit. If 1 => Take that as a yes, else 0 => No
//Yes : Take Number in ACW direction i.e negative
//No  : Take Number in  CW direction i.e positive
void SecondThreadApproach(){
    int n,t,sum;
    cin>>n;
    int* arr = gA(n);
    for(int i=0;i<(1<<n);i++){
        t=i;sum=0;
        for(int j=0;j<n;j++) (t&(1<<j))?(sum+=-arr[j]):(sum+=arr[j]);

        if(sum%360==0){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

//https://codeforces.com/problemset/problem/1097/B
void solve(){
    int n,t,sum,count,mask;
    cin>>n;
    int* arr = gA(n);
    for(int i=0;i<(1<<n);i++){
        t=i;sum=0;count=0,mask=1;
        while(count<n){
            (t&mask)?(sum+=-arr[count]):(sum+=arr[count]);
            mask<<=1;
            count++;
        }
        if(sum%360==0){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;

}




int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    SecondThreadApproach();
    //solve();
    //loopSolve;

	return 0;
}

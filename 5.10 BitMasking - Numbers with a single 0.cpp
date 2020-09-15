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

/*

https://codeforces.com/contest/611/problem/B

Firstly, Numbers with a single 0 has to be generated with numbers that have all 1's.
These can be generated using 2 methods,

M1.
We know, 1^1=0 and 1^0 = 1
=> To remove 0 at ith index of num, construct a number with 1 at ith position and then num=num^(that number)
We can construct that number via 1<<i (For long longs, 1LL<<i) hence, num^=(1<<i);

M2. https://codeforces.com/blog/entry/22441
Consider a number mask, having the following properties
1. mask is a multiple of 2^x, x belongs to Natural Number
2. mask is less than num

num-=mask gives a number with only one zero num-mask here will be equivalent to num^=mask

Here we iterate through all such numbers with one zero and then check if that number is within the given range of the required question

*/


//M2
void ErrichtoMethod(){
    ll a,b;
    cin>>a>>b;
    int ans=0;
    for(int i=1;i<=((int)log2(b)+1);i++){       //log2(b)+1 counts the number of bits in a number
        for(int j=0;j<i-1;j++){
            ll num = (1LL<<i)-1 -(1LL<<j);      //Notice that (1LL<<i)-1 = 11111...till ith bit
            if(num>=a && num<=b) ans++;
        }
    }
    cout<<ans<<endl;

}



//M1
ll getCount(int n){
    return (n*(n-1))/2;
}

void solve(){
    ll a,b;
    cin>>a>>b;
    ll t,ans=0,ctr=0,A=0,B=0,availB=0;

    t=a;
    while(t>0){
        ctr++;
        t>>=1;
    }
    A=ctr;

    t=b;ctr=0;
    while(t>0){
        ctr++;
        t>>=1;
    }
    B=ctr;

    ans = getCount(B-1) - getCount(A-1);

    ll num;
    for(int i=0;i<B-1;i++){
        num = power(2,B)-1;
        num^=(1LL<<i);
        if(num<=b)
            availB++;
    }

    for(int i=0;i<A-1;i++){
        num = power(2,A)-1;
        num^=(1LL<<i);
        if(num<a)
            ans--;
    }
    ans+=availB;

    cout<<ans<<endl;

}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    ErrichtoMethod();
    //solve();
    //loopSolve;

	return 0;
}

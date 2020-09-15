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

//https://codeforces.com/problemset/problem/1202/A
void solve(){
   string x,y;
   cin>>x>>y;
   int i1,i2,k=0;
   for(int i=y.length()-1;i>=0;i--){
        if(y[i]=='1'){
            i2=(y.length()-1)-i;
            break;
        }
   }

   for(int i=x.length()-1;i>=0;i--){
        if(x[i]=='1'){
            i1=(x.length()-1)-i;
            if(i1>=i2){
                k=i1-i2;
                break;
            }
        }
   }

    cout<<k<<endl;
}
//Key Observations
/*
1. Multiplying a number by 2^k is equivalent to padding k zeroes at the end of the number
2. For reverse string to be lexicographically minimal
    i) Find the index of 1st set bit from LSB side of y (i.e 1st set after all trailing zeroes are removed). Above, it is i2
    ii) Now the idea is to match this set bit with a set bit from x. Hence now, find indices of all set bits of x from LSB side, such that the index i1>=i2. If not,
        then i2 will never be able to match with i1, when placed then together. The difference can be accounted for by padding the string with k zeroes, where k = i1-i2
For example
x = 1010
y = 11
i2 = fixed = 0 (from LSB side)
i1 = 1 or 2
For i1 = 1, i2 can be padded with one(1=i1-i2=k) 0 and hence the 1st set bit from LSB of y is matched with a set bit of x

Example 2
x = 10001
y = 110
i2 = fixed = 1 (from LSB side)
i1 = 0 or 4
Now, for i1=0, set bit from y at i2=1 cannot be matched with x, hence discard this case
for i1=4, set bit from y at i2=1 can be matched by padding y with three(3=i1-i2=k) 0's

Example 3
x = 1010101010101
y = 11110000
i2 = 4
i1 = 0,2,4,....
for i1=i2=4, match is complete => k=4-4=0

ALSO REFER TO THE TUTORIAL OVER HERE ... https://codeforces.com/blog/entry/68972
*/



int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //solve();
    loopSolve;

	return 0;
}

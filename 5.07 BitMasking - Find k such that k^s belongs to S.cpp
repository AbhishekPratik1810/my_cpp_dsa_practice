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

/*
M2
If k>1023(NMax) => k^s> 1023 (as the set bit from MSB side will always XOR with 0 to give 1 and hence make the number greater than or equal to 1024) which we don't want
For example k = 1000001001 (2^10 + 2^3 + 1)
            s = 01111111111
          k^s = 11111110110 (Note the first bit from MSB makes k^s >1024)
Hence check for all k between k=1 and k=1023 and see if it satisfies the criteria. Else print -1
*/
void method2(){
    int n,k=-1;
    cin>>n;
    int* arr = new int[n];

    map<int,int> nums;
    fo{ cin>>arr[i]; nums[arr[i]]++; }
    map<int,int> temp;

    for(int i=1;i<1024;i++){
        bool pass=true;
        temp=nums;
        for(int j=0;j<n;j++){
            if(temp[arr[j]^i]>0) temp[arr[j]^i]--;
            else {pass=false;break;}
        }
        if(pass){k=i;break;}
    }

    cout<<k<<endl;

}


/*
M1
Suppose such a k exits
Let 'b' belong to S => For all 'b', there exists 'a' such that a belongs to S and k^a = b (also a!=b as k>0)
=> k^a = b
=> k^a^a = b
=> k = a^b
=> We find all such values of k by going through all such a,b pairs
*/
void solve(){
    int n;
    cin>>n;
    int* arr = new int[n];
    map<int,bool> nums;
    fo{
        cin>>arr[i];
        nums[arr[i]]=true;
    }
    set<int> vals;
    fo{
        for(int j=i;j<n;j++){
            vals.insert(arr[i]^arr[j]);
        }
    }

    for(auto val:vals){
        cout<<val<<" ";
    }
    cout<<endl;

    for(auto val : vals){
        if(val==0)
            continue;
        bool flag=true;
        for(int i=0;i<n;i++){
            if(!(nums[arr[i]^val])){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<val<<endl;
            return;
        }
    }
    cout<<-1<<endl;

}




int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //solve();
    loopSolve;

	return 0;
}

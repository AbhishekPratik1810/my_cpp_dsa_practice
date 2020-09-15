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

map<char,char> mp;


/*
MANY KEY OBSERVATIONS
1. THE MOST IMPORTANT. PASS BY REFERENCE AND NOT VALUE IN RECURSION. ELSE YOU WILL GET TLE. THIS IS BECAUSE IF STRING HAS VERY LARGE LENGTH, THEN TO CREATE A COPY OF IT WILL TAKE A LOT OF TIME
2. If you want to return either 0 or 1, instead of using an if else statement, you can return the boolean expression
3. STL IS AWESOME. Use it, wherever you can.
4. Time Complexity = O(nlogn+n) = O(nlogn) //Master Theorem
*/
int elegantSolve(const string& s,char ch){
    if(s.size()==1)
        return s[0]!=ch;

    int lc,rc,mid=s.size()/2;
    lc=count(s.begin(),s.begin()+mid,ch);
    rc=count(s.begin()+mid,s.end(),ch);

    return min(mid-lc+elegantSolve(string(s.begin()+mid,s.end()),ch+1), mid-rc+elegantSolve(string(s.begin(),s.begin()+mid),ch+1));

}
//https://codeforces.com/contest/1385/problem/D
int whereMagicHappens(string s,int first,int last,char ch){
    if(first==last)
        return s[first-1]==ch?0:1;
    else{
        int leftCount=0,rightCount=0,middle=(first+last)/2;

        for(int i=first-1;i<middle;i++)
            if(s[i]!=ch)
                leftCount++;

        for(int i=middle;i<last;i++)
            if(s[i]!=ch)
               rightCount++;

        int secondRight,secondLeft;
        secondRight=whereMagicHappens(s,middle+1,last,mp[ch]);
        secondLeft=whereMagicHappens(s,first,middle,mp[ch]);

        return min(leftCount+secondRight,rightCount+secondLeft);
    }
}

void solve(){
    int n; string s;
    cin>>n>>s;
    cout<<whereMagicHappens(s,1,n,'a')<<endl;
    cout<<elegantSolve(s,'a')<<endl;
}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    mp['z']='a';
    for(int i=0;i<25;i++)
        mp[i+97]=i+98;
    //solve();
    loopSolve;
	return 0;
}

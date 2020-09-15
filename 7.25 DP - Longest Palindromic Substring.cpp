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

//https://leetcode.com/problems/longest-palindromic-substring/
// 188ms | 10.6MB
string longestPalindromeSubstring(string x) {
    int len = x.size();
    static int dp[1001][1001];  //dp[i][j] means longest palindromic substring, which NECESSARILY starts at x[i-1] and ends at x[j-1]
                                //(i.e INCLUDING BOTH OF THEM as their beginning and ending characters)

    for(int i=1;i<=len;i++) {dp[0][i]=0;dp[i][0]=0;}
    for(int i=1;i<=len;i++) {dp[i][i]=1;}

    int ans=1,idx=1;                        //All strings of length > 0 have one palindromic substring. for ex, abc has 'a','b','c' as valid palindromic substrings
    for(int d=1;d<len;d++){
        for(int i=1;i<=len-d;i++){
            int j=i+d;

            if(x[i-1]==x[j-1] && (dp[i+1][j-1]>0 || j==i+1))
                dp[i][j]=dp[i+1][j-1]+2;
            else
                dp[i][j]=0;                //This means that there exists no palindromic substring, which starts at the (i-1)th character and ends at (j-1)th character
                                           //For example, in abcba, if i=1, and j=4, then there exists no palindromic sequence which begins with 'a' and ends with 'b' (the 0th and 3rd characters of abcba)

            if(dp[i][j]>ans){
                ans=dp[i][j];
                idx=j;
            }

        }
    }

    vector<char> common;
    while(ans!=0){
        common.push_back(x[idx-1]);
        idx--;
        ans--;
    }
    string s(common.begin(),common.end());
    return s;

}

int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //solve();
    //loopSolve;
    cout<<longestPalindromeSubstring("aacdefcaa")<<endl;
    cout<<longestPalindromeSubstring("abcba")<<endl;
	return 0;
}

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


// https://leetcode.com/problems/longest-palindromic-subsequence/
//O(l1*l2) | O(l1*l2) 104 ms | 10.8 MB
int longestPalindromeSubseq(string x) {
        string y=x;
        reverse(y.begin(),y.end());
        int l1=x.length(),l2=y.length();

        static int dp[1001][1001];
        for(int i=0;i<=1000;i++){dp[i][0]=0;dp[0][i]=0;}

        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(x[i-1]==y[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[l1][l2];

}

void printLongestPalindromicSubseq(string x){
        string y=x;
        reverse(y.begin(),y.end());
        int l1=x.length(),l2=y.length();

        static int dp[1001][1001];
        for(int i=0;i<=1000;i++){dp[i][0]=0;dp[0][i]=0;}

        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(x[i-1]==y[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        int i=l1,j=l2,current = dp[l1][l2];
        vector<char> ans;
        while(current!=0){
            if(x[i-1]==y[j-1]){
                ans.push_back(x[i-1]);
                i--;j--;current--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
        //No need to reverse ans as ans is palindrome :)
        for(auto c:ans)
            cout<<c;
        cout<<endl;
}
// 80ms | 10.2 MB
int withoutLCS(string x){

    int len=x.size();
    static int dp[1001][1001];          //dp[i][j] represents the state : total palindromic sequence from x[i-1] till x[j-1]
                                        //or if you think via 1 based indexing, total palindromic sequence in the substring of x starting at ith index and ending at jth index

    for(int i=1;i<=len;i++) {dp[0][i]=0;dp[i][0]=0;}
    for(int i=1;i<=len;i++) dp[i][i]=1;

    for(int i=len;i>=1;i--){                            //Require a state which is ahead then the current one?(like dp[i+1][j]), start i from behind, so that dp[i+1][j] has been calculated beforehand
        for(int j=i+1;j<=len;j++){
            if(x[i-1]==x[j-1])
                dp[i][j]=dp[i+1][j-1]+2;
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);   //j-1>=i and dp[i][i] is base case which is calculated. Also, dp[i][j-1] was just calculated previously, so accessing it is not an issue
        }
    }
    return dp[1][len];
}

//More intuitive 104ms | 10.8MB
int reallyCleverSolution(string x){

    int len=x.size();
    static int dp[1001][1001];          //dp[i][j] represents the state : total palindromic sequence from x[i-1] till x[j-1]
                                        //or if you think via 1 based indexing, total palindromic sequence in the substring of x starting at ith index and ending at jth index

    for(int i=1;i<=len;i++) {dp[0][i]=0;dp[i][0]=0;}
    for(int i=1;i<=len;i++) {dp[i][i]=1;}

    for (int d=1;d<len;d++) {
        for (int i=1;i<=len-d;i++) {
            int j=i+d;                                          // total interval length which will be spanned is d, hence doing computation and storing for length spanned = d
            if (x[i-1]==x[j-1]) dp[i][j]=2+dp[i+1][j-1];        // fetching info for length spanned = (i+d-1)-(i+1) = d-2 which has been calculated before so possible to do this
            else dp[i][j]=max(dp[i][j-1], dp[i+1][j]);          // fetching info for lengths spanned = (i+d)-(i+1) = d-1 and (i+d-1)-(i) = d-1 which has been calculated before
        }
    }
    return dp[1][len];

}

int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //solve();
    string testCase = "GEEKSFORGEEKS";
    cout<<longestPalindromeSubseq(testCase)<<endl;
    cout<<reallyCleverSolution(testCase)<<endl;
    printLongestPalindromicSubseq(testCase);

	return 0;
}

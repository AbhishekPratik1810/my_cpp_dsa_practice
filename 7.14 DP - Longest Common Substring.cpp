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

void printLCSubstring(){
    int l1,l2; cin>>l1>>l2;
    string s1,s2; cin>>s1>>s2;

    int dp[101][101];               //dp[i][j] means length of the "current"(not longest) substring having  s1[i-1] and s2[j-1] common NECESSARILY
    for(int i=0;i<=100;i++){
        dp[i][0]=0;dp[0][i]=0;
    }

    int ans=0,idx;
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];    //Both letters are common, hurray, update the current common substring length with 1
            }else{
                dp[i][j]=0;                 //Obviously, if s1[i-1]!=s2[j-1] then length of the current substring having s1[i-1] and s2[j-1] common is 0, as the letters themselves aren't common
            }
            if(dp[i][j]>ans){
                ans=dp[i][j];
                idx=i;                      //even j, doesn't matter
            }
        }
    }

    vector<char> common;
    while(ans!=0){
        common.pb(s1[idx-1]);               //if j was taken, then it would have been common.pb(s2[j-1])
        ans--;
        idx--;
    }
    reverse(common.begin(),common.end());
    for(auto c : common )
        cout<<c;
    cout<<endl;
}

void dpApproach(){
    int l1,l2; cin>>l1>>l2;
    string s1,s2; cin>>s1>>s2;

    int dp[101][101];               //dp[i][j] means length of the "current"(not longest) substring having  s1[i-1] and s2[j-1] common NECESSARILY
    for(int i=0;i<=100;i++){
        dp[i][0]=0;dp[0][i]=0;
    }

    int ans=0;
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];    //Both letters are common, hurray, update the current common substring length with 1
            }else{
                dp[i][j]=0;                 //Obviously, if s1[i-1]!=s2[j-1] then length of the current substring having s1[i-1] and s2[j-1] common is 0, as the letters themselves aren't common
            }
            ans=max(ans,dp[i][j]);
        }
    }

    cout<<ans<<endl;

}

void naivePatheticApproach(){
    int l1,l2; cin>>l1>>l2;
    string s1,s2; cin>>s1>>s2;
    if(l1<l2){
        swap(l1,l2);swap(s1,s2);  //Ensured s1 is always the longest string
    }

    int ans=0,longest,pos1;
    for(int i=0;i<l1;i++){
        longest=0,pos1=i;
        for(int j=0;j<l2;j++){

            if(s1[pos1]==s2[j]){
                longest++;
                pos1++;
                if(pos1>=l1) break;
            }else{
                if(s1[i]==s2[j]){                     //For testCases 2 and 3
                    ans=max(ans,max(longest,1));
                    longest=1;
                    if(pos1>=l1) break;
                    pos1=i+1;
                }else{
                    ans=max(ans,longest);
                    longest=0;
                    pos1=i;
                }

            }
        }
        ans=max(ans,longest);                       //If if never goes to else i.e the last characters were also a match
    }

    cout<<ans<<endl;

}
/*
7 78
RSVBSPK
YHSENBPPKQTPDDBUOTBBQCWIVRFXJUJJDDNTGEIQVDGAIJVWCYAUBWEWPJVYGEHLJXEPBPIWUQZDZU
*/

/*
3 3
MHM
MMH
*/

/*
27 52
IGUYDOUEWZJLKRMMHBKQLMZXZOP
SSGMCNICSWXWTWHEIBQVITHYEVZEVPTNICCKPKNJHMHAKOGSPYPZ
*/


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //solve();
    //loopSolve;
    //naivePatheticApproach();
    dpApproach();
    printLCSubstring();

	return 0;
}

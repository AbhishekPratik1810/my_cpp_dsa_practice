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


void usingLCS(){
    //Use the fact that adding both the strings and removing the longest common subsequence gives the smallest common supersequence
    string x,y; cin>>x>>y;
    int l1=x.length(),l2=y.length();
    int dp[101][101];
    for(int i=0;i<=100;i++) {dp[0][i]=0;dp[i][0]=0;}

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(x[i-1]==y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        }
    }

    cout<<l1+l2-dp[l1][l2]<<endl;
}

//Note that this is more time consuming, as using the + operator in line 63 will create a copy of dp[i-1][j-1] and that will take O(dp[i-1][j-1].size())
//O(n*m) | O(n*m*min(m,n)) roughly O(n^2)|O(n^3)  Why min(m,n)? think of these 2 examples aaaaaaaa|aaaaaaaa and aaaaaaaa|aaaaa  as Worst Case
string getLCS(string &x, string &y){
    int l1=x.length(),l2=y.length();
    vector<vector<string>> dp(l1+1,vector<string>(l2+1,""));

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1]+x[i-1];
            }else{
                dp[i][j]=dp[i-1][j].size()>dp[i][j-1].size()?dp[i-1][j]:dp[i][j-1];
            }
        }
    }

    return dp[l1][l2];
}

void elegantPrint(){
    string x,y; cin>>x>>y;

    string common = getLCS(x,y);

    string ans;
    int i=0,j=0;
    for(int k=0;k<common.size();k++){
        while(x[i]!=common[k])
            ans+=x[i++];
        while(y[j]!=common[k])
            ans+=y[j++];
        ans+=common[k]; i++;j++;
    }
    ans+=x.substr(i)+y.substr(j);
    cout<<ans<<endl;
}

void fasterPrint(){
    string x,y; cin>>x>>y;
    int l1=x.length(),l2=y.length();

    //LCS
    static int dp[1001][1001];
    for(int i=1;i<=l1;i++) dp[i][0]=0;
    for(int i=1;i<=l2;i++) dp[0][i]=0;
    dp[0][0]=0;
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    vector<char> cv;
    int cl=dp[l1][l2],i=l1,j=l2;
    while(cl!=0){
        if(x[i-1]==y[j-1]){ cv.push_back(x[i-1]); cl--;i--;j--;}
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;

    }

    reverse(cv.begin(),cv.end());
    string common(cv.begin(),cv.end());                             //Largest Common Subsequence

    vector<vector<char>> build(common.size()+1);
    int beg=0,prev=0;
    for(int i=0;i<l1;i++){
        if(beg<common.size() && x[i]==common[beg]){
            for(int j=prev;j<i;j++)
                build[beg].push_back(x[j]);
            beg++;
            prev=i+1;
        }
        else if(beg>=common.size()){
            for(int j=i;j<l1;j++)
                build[beg].push_back(x[j]);
            break;
        }
    }

    beg=0;prev=0;
    for(int i=0;i<l2;i++){
        if(beg<common.size() && y[i]==common[beg]){
            for(int j=prev;j<i;j++)
                build[beg].push_back(y[j]);
            beg++;
            prev=i+1;
        }

        else if(beg>=common.size()){
            for(int j=i;j<l2;j++)
                build[beg].push_back(y[j]);

            break;
        }
    }

    string ans;
    for(int i=0;i<=common.size();i++){
        if(i<common.size())
            build[i].push_back(common[i]);
        for(int j=0;j<build[i].size();j++){
            ans+=build[i][j];
        }
    }

    cout<<ans<<endl;

}

void printSCS(){
    string x,y; cin>>x>>y;
    int l1=x.length(),l2=y.length();
    static int dp[1001][1001];
    for(int i=0;i<=1000;i++) {dp[0][i]=i;dp[i][0]=i;}
    vector<string> mp((l1+1)*(l2+1)+l2);                          //can even use a map<int,string> but apparently vector is faster


    for(int i=1;i<=l1;i++){
        mp[i*(l2+1)]=mp[(i-1)*(l2+1)]+x[i-1];
    }
    for(int j=1;j<=l2;j++){
        mp[j]=mp[j-1]+y[j-1];
    }

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                mp[i*(l2+1)+j]=mp[(i-1)*(l2+1)+j-1]+x[i-1];     //arr[i][j] = i*(col+1) + j
            }
            else{
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;          //think about geek|ee , geek|ees(for why not max(..,..)) , gee|eke
                if(dp[i-1][j]>dp[i][j-1]){
                    mp[i*(l2+1)+j]=mp[i*(l2+1)+j-1]+y[j-1];
                }else{
                    mp[i*(l2+1)+j]=mp[(i-1)*(l2+1)+j]+x[i-1];
                }
            }

        }
    }

    cout<<mp[l1*(l2+1)+l2]<<endl;

}

void solve(){
    string x,y; cin>>x>>y;
    int l1=x.length(),l2=y.length();
    int dp[101][101];
    for(int i=0;i<=100;i++) {dp[0][i]=i;dp[i][0]=i;}

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(x[i-1]==y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;          //think about geek|ee , geek|ees(for why not max(..,..)) , gee|eke

        }
    }
    cout<<dp[l1][l2]<<endl;

}

/*
atdznrqfwlfbcqkezrltzyeqvqemikzgghxkzenhtapwrmrovwtpzzsyiwongllqmvptwammerobtgmkpowndejvbuwbporfyroknrjoekdgqqlgzxiisweeegxajqlradgcciavbpgqjzwtdetmtallzyukdztoxysggrqkliixnagwzmassthjecvfzmyonglocmvjnxkcwqqvgrzpsswnigjthtkuawirecfuzrbifgwolpnhcapzxwmfhvpfmqapdxgmddsdlhteugqoyepbztspgojbrmpjmwmhnldunskpvwprzrudbmtwdvgyghgprqcdgqjjbyfsujnnssfqvjhnvcotynidziswpzhkdszbblustoxwtlhkowpatbypvkmajumsxqqunlxxvfezayrolwezfzfyzmmneepwshpemynwzyunsxgjflnqmfghsvwpknqhclhrlmnrljwabwpxomwhuhffpfinhnairblcayygghzqmotwrywqayvvgohmujneqlzurxcpnwdipldofyvfdurbsoxdurlofkqnrjomszjimrxbqzyazakkizojwkuzcacnbdifesoiesmkbyffcxhqgqyhwyubtsrqarqagogrnaxuzyggknksrfdrmnoxrctntngdxxechxrsbyhtlbmzgmcqopyixdomhnmvnsafphpkdgndcscbwyhueytaeodlhlzczmpqqmnilliydwtxtpedbncvsqauopbvygqdtcwehffagxmyoalogetacehnbfxlqhklvxfzmrjqofaesvuzfczeuqegwpcmahhpzodsmpvrvkzxxtsdsxwixiraphjlqawxinlwfspdlscdswtgjpoiixbvmpzilxrnpdvigpccnngxmlzoentslzyjjpkxemyiemoluhqifyonbnizcjrlmuylezdkkztcphlmwhnkdguhelqzjgvjtrzofmtpuhifoqnokonhqtzxmimp
xjtuwbmvsdeogmnzorndhmjoqnqjnhmfueifqwleggctttilmfokpgotfykyzdhfafiervrsyuiseumzmymtvsdsowmovagekhevyqhifwevpepgmyhnagjtsciaecswebcuvxoavfgejqrxuvnhvkmolclecqsnsrjmxyokbkesaugbydfsupuqanetgunlqmundxvduqmzidatemaqmzzzfjpgmhyoktbdgpgbmjkhmfjtsxjqbfspedhzrxavhngtnuykpapwluameeqlutkyzyeffmqdsjyklmrxtioawcrvmsthbebdqqrpphncthosljfaeidboyekxezqtzlizqcvvxehrcskstshupglzgmbretpyehtavxegmbtznhpbczdjlzibnouxlxkeiedzoohoxhnhzqqaxdwetyudhyqvdhrggrszqeqkqqnunxqyyagyoptfkolieayokryidtctemtesuhbzczzvhlbbhnufjjocporuzuevofbuevuxhgexmckifntngaohfwqdakyobcooubdvypxjjxeugzdmapyamuwqtnqspsznyszhwqdqjxsmhdlkwkvlkdbjngvdmhvbllqqlcemkqxxdlldcfthjdqkyjrrjqqqpnmmelrwhtyugieuppqqtwychtpjmloxsckhzyitomjzypisxzztdwxhddvtvpleqdwamfnhhkszsfgfcdvakyqmmusdvihobdktesudmgmuaoovskvcapucntotdqxkrovzrtrrfvoczkfexwxujizcfiqflpbuuoyfuoovypstrtrxjuuecpjimbutnvqtiqvesaxrvzyxcwslttrgknbdcvvtkfqfzwudspeposxrfkkeqmdvlpazzjnywxjyaquirqpinaennweuobqvxnomuejansapnsrqivcateqngychblywxtdwntancarldwnloqyywrxrganyehkglbdeyshpodpmdchbcc
*/

/*
hxmngqmf gnapcnty
*/

/*
gee
eke
*/

/*
geek
eke
*/

int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //solve();
    //usingLCS();
    //printSCS();
    //loopSolve;
    //fasterPrint();
    elegantPrint();
	return 0;
}

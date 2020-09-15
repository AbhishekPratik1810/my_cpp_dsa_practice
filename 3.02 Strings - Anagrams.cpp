#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define clear cin.clear();cin.ignore(numeric_limits<streamsize>::max(), '\n');
//INT_MAX         2,147,483,647                       <10^10
//U_INT_MAX       4,294,967,295                       <10^10
//LONG_LONG_MAX   9,223,372,036,854,775,807           <10^18
//U_LONG_LONG_MAX 18,446,744,073,709,551,615          <10^18


/*ll power(int a, int b){
    return (ll)(pow(a,b)+0.5);
}*/

void solve(){
    string s1,s2;
    cin>>s1>>s2;
    //For getting an entire line as input, use the below commented code
    /*getline(cin,s1);
    regex reg("\\s+");            //Used "\\s+" instead of " " as it accounts for multiple spaces, unlike " " which accounts for a single whitespace
    vector<string> result{sregex_token_iterator(s1.begin(), s1.end(), reg, -1), {}};
    s1=result[0];s2=result[1];
    cout<<s1<<endl<<s2;*/
    int bitset1[256] = {0};

    for(int i=0;s1[i]!='\0';i++)
        bitset1[s1[i]]++;
    for(int i=0;s2[i]!='\0';i++){
        bitset1[s2[i]]--;
        if(bitset1[s2[i]]<0){
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i=0;i<256;i++){
        if(bitset1[i]!=0){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;


}



int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }


	return 0;
}



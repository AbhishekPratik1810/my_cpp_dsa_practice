#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fo for(int i=0;i<n;i++)
#define clear cin.clear();cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define loopSolve int t; cin>>t; while(t--){solve();}
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

//INT_MAX         2,147,483,647                       <10^10
//U_INT_MAX       4,294,967,295                       <10^10
//LONG_LONG_MAX   9,223,372,036,854,775,807           <10^18
//U_LONG_LONG_MAX 18,446,744,073,709,551,615          <10^18
//ll power(int a, int b){
//    return (ll)(pow(a,b)+0.5);
//}

vector<int> gV(int n){
    vector<int> v(n);
    fo { cin>>v[i];  }
    return v;
}

int* gA(int n){
    int* arr = new int[n];
    fo cin>>arr[i];
    return arr;
}




void solve(){
    int row,col;
    cin>>row>>col;
    char** inp = new char* [row];
    for(int i=0;i<row;i++)
        inp[i]=new char[col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>inp[i][j];
        }
    }

    int** down = new int* [row+1];
    int** across = new int* [row+1];
    for(int i=0;i<=row;i++){
        down[i]=new int[col+1];
        across[i]=new int[col+1];
    }

    for(int i=0;i<=row;i++){
        for(int j=0;j<=col;j++){
            down[i][j]=0; across[i][j]=0;
        }

    }

    int ans=0;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(inp[i-1][j-1]=='.'){
                if(down[i-1][j]&&across[i][j-1]){
                    down[i][j]=down[i-1][j];
                    across[i][j]=across[i][j-1];
                    ans=max(ans,down[i][j]+across[i][j]-1);                         //-1 ans I have always included the current '.' in both across and down =>counted twice
                }else{                                                              //prev input is '#' or 1st col/ 1st row
                    int goingRight=j,countAcross=0,goingDown=i,countDown=0;
                    if(down[i-1][j]){
                        //across is 0;
                        while(goingRight<=col && inp[i-1][goingRight-1]=='.'){
                            countAcross++;
                            goingRight++;
                        }
                        down[i][j]=down[i-1][j];
                        across[i][j]=countAcross;
                    }else if(across[i][j-1]){
                        //down is 0;
                        while(goingDown<=row && inp[goingDown-1][j-1]=='.'){
                            countDown++;
                            goingDown++;
                        }
                        down[i][j]=countDown;
                        across[i][j]=across[i][j-1];
                    }else{
                        while(goingRight<=col && inp[i-1][goingRight-1]=='.'){
                            countAcross++;
                            goingRight++;
                        }
                        while(goingDown<=row && inp[goingDown-1][j-1]=='.'){
                            countDown++;
                            goingDown++;
                        }
                        down[i][j]=countDown;
                        across[i][j]=countAcross;
                    }
                    ans=max(ans,down[i][j]+across[i][j]-1);
                }

            }
        }
    }
    cout<<ans<<endl;

}

void bruteForce(){
    ll row,col;
    cin>>row>>col;
    char** input = new char*[row];
    for(int i=0;i<row;i++)
        input[i]=new char[col];

    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            cin>>input[i-1][j-1];
        }
    }
    ll ans=INT_MIN;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(input[i-1][j-1]=='.'){
                int k=j+1; ll temp=0;
                while(k<=col&&input[i-1][k-1]!='#'){
                    temp++;
                    k++;
                }

                k=j-1;
                while(k>0&&input[i-1][k-1]!='#'){
                    temp++;
                    k--;
                }


                k=i-1;
                while(k>0 && input[k-1][j-1]!='#'){
                    temp++;
                    k--;
                }

                k=i+1;
                while(k<=row && input[k-1][j-1]!='#'){
                    temp++;
                    k++;
                }

                ans=max(ans,temp+1);
                if(ans==row+col-1)                      //To remove unnecessary computations as this is the max ans one can obtain
                    break;
            }
        }
    }
    cout<<ans<<endl;

}


int main() {
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    //loopSolve;

	return 0;
}

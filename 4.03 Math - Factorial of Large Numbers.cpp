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
    //https://www.geeksforgeeks.org/factorial-large-number/
    int fact[INT_MAX];
    int n,size=2;
    cin>>n;
    fact[0]=n%10;
    fact[1]=(n/10)%10;
    int j=12;
    while(!j%10){
            int dig = j%10,carry =0;
            for(int k=0;k<size;k++){
                int pdt = fact[k]*dig;
                int carry +=pdt/10;
                int result = pdt%10;
            }
            j/=10;
    }

    for(int i=0;i<size;i++){
        cout<<fact[i];
    }
    cout<<endl;

    /*for(int i=0;i<n;i++){
        int j=i+1;
        while(!j%10){
            int dig = j%10;
            for(int k=0;k<?;k++){

            }
            j/=10;
        }
    }*/
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



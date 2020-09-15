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

    //Trailing 0's = number of times n! is divisible by 5 and its multiples as 0's are achieved by 5 multiplying with 2s. for each 5 encountered, a multiple of 2 is also encountered
    ll n;
    cin>>n;
    ll count=0;

    for (ll i = 5; n / i >= 1; i *= 5)
        count += n / i;                   // Say n=100 => i=5 divides n=100 1 times. If we say count+=1, we are only calculating how many times 5 divides 100 and not 100!
                                          //100/5 = 20 and 5 divides 5,10,15,20,25.....100 also 1 times, => n/i used
    cout<<count<<endl;

    //In 1st scan, division by 5^1 occurs, to give numbers only div by 5
    //In 2nd scan, division by 5^2 occurs, to give numbers div by 25, and as 25=5*5, it gives the numbers containing HIDDEN 5
    //In 3rd scan, division by 5^3 occurs, to give numbers div by 125, and as 125=25*5, it gives the numbers containing HIDDEN 25 = 5*5 = 2 HIDDEN 5's and so on

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



#include <iostream>
#define ll long long
using namespace std;

ll factorial(ll n){
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}

int main(){

    ll n;
    cin>>n;
    ll fact = factorial(n);
    cout<<"Factorial of "<<n<<" is "<<fact;

    return 0;
}

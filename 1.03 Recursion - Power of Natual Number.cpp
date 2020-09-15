#include<iostream>
using namespace std;

int power(int b, int n){
    if(n==0)
        return 1;
    else
        return b*power(b,n-1);
}

int fasterPower(int b,int n){
    //Lesser Number of multiplications, Lesser Number of Recursive Calls
    if(n%2==0)
        return power(b*b,n/2);
    else
        return b*power(b*b,n/2);
}

int main(){
    int n,b;
    char c;
    cin>>b>>c>>n;
    int pow = fasterPower(b,n);
    cout<<b<<" to the power "<<n<< " is "<<pow;
    return 0;
}

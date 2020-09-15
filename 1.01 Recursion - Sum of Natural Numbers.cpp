#include <iostream>

using namespace std;

int sumOfNaturalNumber(int);

int main()
{
    int n ;
    cin >> n;
    int sum = sumOfNaturalNumber(n);
    cout<<"Sum is " << sum;
    return 0;
}

int sumOfNaturalNumber(int n){
    if(n>0)
        return n + sumOfNaturalNumber(n-1) ;
    else
        return 0;
}



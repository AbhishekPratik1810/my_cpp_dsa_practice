/*
You have given 4 numbers A, B, C, D and you have to perform an algorithm:-

int sum=0;

for(int i=A;i<=B;i++) {

for(int j=C;j<=D;j++)
    sum+=i^j;

}

As the sum could be very large, compute it modulo 1000000007 (10e9+7).

Constraints : 1<=A,B,C,D<=1000000000

Time Limit — 1 sec

INPUT :- 4 integers A,B,C,D is given.

OUTPUT :- Print the sum after performing the algorithm.

EXAMPLE INPUT:- 1 2 3 4

EXAMPLE OUTPUT:- 14

EXPLANATION :- 1^3+1^4+2^3+2^4

2 + 5 + 1 + 6 = 14
*/

#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int mod = 1e9+7;

int countOnes(int to,int pos){                    //will 1's count from 1-to
    int zeros = (1<<pos) - 1, n = (1<<(pos+1));
	to = max(0, to - zeros);
	return to/n *(n/2) + min(to%n,n/2);
}

int countOnes(int from, int to, int pos){
    return countOnes(to,pos) - countOnes(from-1,pos);
}

int main(){
    int a,b,c,d; cin>>a>>b>>c>>d;           //First interval b/w a-b, Second b/w c-d
    ll ans=0;
    for(int pos=0;pos<=31;pos++){
        int onesFirst  = countOnes(a,b,pos), zerosFirst = (b-a+1)-onesFirst;
        int onesSecond = countOnes(c,d,pos), zerosSecond = (d-c+1)-onesSecond;
        ans+= (1<<pos)*(onesFirst*zerosSecond+zerosFirst*onesSecond);
        ans%=mod;
    }


    cout<<ans<<endl;
}

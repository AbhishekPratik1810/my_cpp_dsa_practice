//https://hack.codingblocks.com/app/practice/1/1264/problem

/*
    After the release of Avengers, Ironman and Thor got into a fight and Ironman challenged Thor to find out the number of numbers between 1 and n
    which are divisible by any of the prime numbers less than 20.
    Ironman being great at maths quickly answered the question but then Thor asked him to write a program for it.
    Ironman however found it quite difficult as he did not wanted to write so many lines of code. he knows that you are smart and can code this up easily. Can you do it?

    Sample Input
    5
    5
    10
    12
    15
    18

    Sample Output
    4
    9
    11
    14
    17
*/

#include<iostream>
using namespace std;

#define ll long long

int main(){

    int k;
    cin>>k;

    while(k--){

        ll n;
        cin>>n;

        int arr[] = {2,3,5,7,11,13,17,19};
        ll ans=0;

        for(int i=1;i<(1<<8);i++){
            int t=i,count=0,pdt=1,pos=0;
            while(t){
                if(t&1){
                    pdt*=arr[pos];
                    count++;
                }
                pos++;
                t>>=1;
            }

            if(count%2)
                ans+=(n/pdt);
            else
                ans-=(n/pdt);

        }

        cout<<ans<<endl;

    }

}

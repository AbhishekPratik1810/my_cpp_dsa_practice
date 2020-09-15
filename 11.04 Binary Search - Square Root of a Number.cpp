#include<iostream>

using namespace std;

int main(){

    int n, uptoDig, start, end, mid;
    cin>>n>>uptoDig;

    start=0, end = n;

    int nearestInteger = n;

    while(start<=end){

        mid = start +(end-start)/2;
        if(mid*mid<=n){
            nearestInteger = min(nearestInteger,mid);
            start = mid+1;
        }else
            end = mid-1;

    }

    float inc = 0.1;
    float sqRoot = nearestInteger;

    for(int i=0;i<uptoDig;i++){

        while(sqRoot*sqRoot<=n)
            sqRoot+=inc;


        sqRoot-=inc;
        inc/=10;

    }

    cout<<sqRoot<<endl;



}

//https://www.spoj.com/problems/PRATA/

#include<iostream>
#include<cmath>
using namespace std;

#define ll long long

ll maxTime = 4004000;                           //1*8+2*8+3*8....1000*8

ll power(int a, int b){
    return (ll)(pow(a,b)+0.5);
}

int count(int rank, ll time){

    ll curr = rank, itr=1;

    while(curr<=time)
        curr += (++itr)*rank;

    itr--;
    return itr;

}

bool possible(ll time, int ranks[], int cooks, int parathas){

    int pCount = 0;

    for(int i=0;i<cooks;i++){
        pCount+=count(ranks[i],time);
    }

    return pCount>=parathas;

}


ll minTime(int ranks[],int cooks, int parathas){

    ll start =0, end = maxTime,mid,ans=maxTime;

    while(start<=end){
        mid = start + (end-start)/2;
        if(possible(mid,ranks,cooks,parathas)){
            ans = min(ans,mid);
            end = mid-1;
        }else
            start = mid+1;
    }
    return ans;

}

int main(){


    int t; cin>>t;

    while(t--){

        int p; cin>>p;
        int cooks; cin>>cooks;
        int ranks[cooks];
        for(int i=0;i<cooks;i++)
            cin>>ranks[i];


        cout<<minTime(ranks,cooks,p)<<endl;


    }

}


#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//https://practice.geeksforgeeks.org/problems/maximize-number-of-1s/0
//https://leetcode.com/problems/max-consecutive-ones-iii/


int elegantSlidingWindow(int n,int k,vector<char> &inp){

    int windowLeft = 0, zeroCount=0, ans=0, idxL=0,idxR=-1;

    for(int windowRight=0;windowRight<n;windowRight++){

        if(inp[windowRight]=='0') zeroCount++;

        while(zeroCount>k){

            if(inp[windowLeft]=='0') zeroCount--;
            windowLeft++;

        }

        if(windowRight-windowLeft+1>ans){
            ans=windowRight-windowLeft+1;
            idxL=windowLeft, idxR=windowRight;
        }
    }

    while(idxL<=idxR)
        inp[idxL++]='1';


    return ans;


}

int slidingWindow(int n,int k, vector<char> &inp){

    int maxSoFar=0, windowLeft=0, windowRight=0, zeroCount=0,ans=0,idx=0, idxL=0,idxR;      //The window always covers 'k' 0's or 'n' 1's

    while(zeroCount<k && idx<n){
        if(inp[idx]=='0') zeroCount++;
        idx++;
    }
    windowRight=idx-1;                      //Sambhal ke karo windowRight ko update warna sab gadbad ho jayega.
    idxR = windowRight;
    maxSoFar = windowRight-windowLeft+1;
    ans = maxSoFar;

    while(windowRight<n-1){

        windowRight++;

        if(inp[windowRight]=='1')
            maxSoFar++;
        else{

            while(inp[windowLeft]!='0')
                windowLeft++;

            windowLeft++;
            maxSoFar = windowRight-windowLeft+1;

        }
        if(ans<maxSoFar){
            ans=maxSoFar;
            idxL=windowLeft; idxR=windowRight;
        }

    }

    while(idxL<=idxR){
        if(inp[idxL]=='0') inp[idxL]='1';
        idxL++;
    }

    return ans;

}


int main(){

    int t; cin>>t;
    while(t--){

        int n,k; cin>>n;
        vector<char> inp(n);

        for(int i=0;i<n;i++)
            cin>>inp[i];

        cin>>k;

        //cout<<slidingWindow(n,k,inp)<<endl;

        cout<<elegantSlidingWindow(n,k,inp)<<endl;

        for(auto c : inp)
            cout<<c<<" ";
        cout<<endl;
    }

}

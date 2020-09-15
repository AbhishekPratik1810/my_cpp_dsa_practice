//https://practice.geeksforgeeks.org/problems/the-painters-partition-problem/0/

#include<iostream>
using namespace std;

int maxTime = 25000;            //max(times[i])*max(boards)

bool possible(int expectedTime, int painters, int boards, int times[]){

    for(int i=0;i<boards;i++)
        if(times[i]>expectedTime)
            return 0;

    int currPainters = 1, currTime = times[0];

    for(int i=1;i<boards;i++){
        if(currTime+times[i]>expectedTime){
            currPainters++;
            currTime=times[i];
        }else
            currTime+=times[i];
    }

    return currPainters<=painters;

}

int minTime(int painters, int boards, int times[]){

    int start=1, end = maxTime, mid, ans=maxTime;

    while(start<=end){

        mid = start + (end-start)/2;

        if(possible(mid,painters,boards,times)){
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

        int painters, boards;
        cin>>painters>>boards;
        int times[boards];

        for(int i=0;i<boards;i++)
            cin>>times[i];

        cout<<minTime(painters,boards,times)<<endl;


    }

}

//https://www.spoj.com/problems/EKO/

#include<iostream>
using namespace std;

int maxPossible = 2e9;

bool possible(int currHeight, int n, long long minWood, int trees[]){

    long long currWood=0;

    for(int i=0;i<n;i++)
        currWood+=max(trees[i]-currHeight,0);


    return currWood>=minWood;


}

int minBladeHeight(int n, int m, int trees[]){

    int start = 0, end = maxPossible, mid, ans = 0;

    while(start<=end){
        mid = start + (end-start)/2;
        if(possible(mid,n,m,trees)){
            ans = max(ans,mid);
            start = mid+1;
        }else
            end = mid-1;
    }

    return ans;



}

int main(){


    int n,m;
    cin>>n>>m;

    int trees[n];
    for(int i=0;i<n;i++)
        cin>>trees[i];

    cout<<minBladeHeight(n,m,trees)<<endl;

}

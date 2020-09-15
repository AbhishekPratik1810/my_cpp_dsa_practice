//https://www.spoj.com/problems/AGGRCOW/

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

bool possible(int arr[],int distance, int cows,int n){

    int count=1,curr=arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]-curr>=distance){
            count++;
            curr = arr[i];
        }
    }

    return count>=cows;


}


int minDistance(int arr[], int cows, int n){

    int start = 0, end = 1e9, ans=0,mid;

    while(start<=end){

        mid = start + (end-start)/2;

        if(possible(arr,mid,cows,n)){
            ans = max(ans,mid);
            start = mid+1;
        }else{
            end = mid-1;
        }

    }

    return ans;


}

int main(){

    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);


    int t; cin>>t;

    while(t--){

        int n,c;
        cin>>n>>c;

        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        sort(arr,arr+n);

        cout<<minDistance(arr,c,n)<<endl;

    }

}

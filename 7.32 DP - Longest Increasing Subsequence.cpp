#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

//O(n*n)
int LIS(){
    int n; cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int* dp = new int[n];               //dp[i] : length of LIS including arr[i]
    int ans=INT_MIN;

    for(int i=0;i<n;i++){
        int bestPrev=0;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i])
                bestPrev=max(bestPrev,dp[j]);
        }
        dp[i]=bestPrev+1;
        ans=max(ans,dp[i]);
    }

    return ans;

    delete[] arr;   delete[] dp;   arr=NULL; dp=NULL;
}

//O(nlogn)
int fasterLCS(){
    int n; cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int* dp = new int[n+1];               //dp[i] : smallest element in arr such that the length of LIS is 'i' , 1<=i<=n
    dp[0]=INT_MIN;
    for(int i=1;i<=n;i++) dp[i]=INT_MAX;

    for(int i=0;i<n;i++){

        int start = 0, last = n;
        while(start<=last){

            int mid = (start+last)/2;

            if(arr[i]<=dp[mid])
                last=mid-1;
            else if(dp[mid+1]<=arr[i])
                start=mid+1;
            else{
                dp[mid+1]=min(dp[mid+1],arr[i]);        //dp[mid]<arr[i]<dp[mid+1] | dp[mid]<arr[i] =>Hey we found LIS of length mid+1. If arr[i]<dp[mid+1] => Hey the smallest element to store at dp[mid+1] = arr[i]
                break;
            }
        }

    }

    for(int i=n;i>=1;i--)
        if(dp[i]!=INT_MAX) return i;

    return 0;
}
//O(nlogn)
int usingSTL(){
    int n; cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int* dp = new int[n+1];               //dp[i] : smallest element in arr such that the length of LIS is 'i' , 1<=i<=n
    dp[0]=INT_MIN;
    for(int i=1;i<=n;i++) dp[i]=INT_MAX;

    for(int i=0;i<n;i++){

        int toUpdate = upper_bound(dp,dp+n+1,arr[i])-dp;
        if(dp[toUpdate-1]<arr[i])                           //with upper_bound, we have ensured that arr[i]<dp[toUpdate]
            dp[toUpdate]=min(dp[toUpdate],arr[i]);
    }

    for(int i=n;i>=1;i--)
        if(dp[i]!=INT_MAX) return i;

    return 0;
}

int main(){
    int t; cin>>t;
    while(t--){
        cout<<usingSTL()<<endl;
    }
}

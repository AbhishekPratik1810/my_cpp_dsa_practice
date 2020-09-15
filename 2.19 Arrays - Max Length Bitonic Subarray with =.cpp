/*
You are provided n numbers of array. You need to find the maximum length of bitonic subarray.
A subarray A[i … j] is biotonic if there is a k with i <= k <= j such that A[i] <= A[i + 1] … <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j]
i.e subarray is first increasing and then decreasing or entirely increasing or decreasing.
*/

#include<iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t; cin>>t;

    while(t--){

        int n; cin>>n;
        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        if(n==1)
            cout<<1<<endl;

        else{

            int startingCount=1, currCount=1, ans=0;
            bool dec = false;

            for(int i=1;i<=n-2;i++){

                if(arr[i]<arr[i-1]) dec = 1;

                if(dec && arr[i]==arr[i+1]){
                    startingCount++;
                    currCount++;
                }else if(dec && arr[i]<arr[i+1]){
                    dec = 0;
                    ans = max(ans,currCount+1);
                    currCount = startingCount;
                    startingCount=1;
                }else
                    currCount++;

            }

            currCount++;                        //Ending and Starting are always part of the current Bitonic sequence

            ans = max(ans,currCount);

            cout<<ans<<endl;

        }

    }

}



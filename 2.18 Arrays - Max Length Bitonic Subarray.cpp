//https://practice.geeksforgeeks.org/problems/maximum-length-bitonic-subarray/0
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

            int currCount=1, ans=0;


            for(int i=1;i<=n-2;i++){

                if(arr[i]==arr[i+1]){
                    ans = max(ans,currCount);
                    currCount = 1;
                }
                else if(arr[i]<arr[i-1] && arr[i]<arr[i+1]){
                    ans = max(ans,currCount+1);
                    currCount=1;
                }else
                    currCount++;

            }

            currCount++;                        //Ending and Starting are always part of the current Bitonic sequence

            ans = max(ans,currCount);

            cout<<ans<<endl;

        }

    }

}



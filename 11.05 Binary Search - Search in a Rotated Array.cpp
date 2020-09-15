//https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array/0

#include<iostream>
#include<climits>
using namespace std;

int searchedIndex(int nums[], int key, int n){

    int ans=-1;

    int start=0, end=n-1, mid;

    while(start<=end){

        mid = start + (end-start)/2;

        if(nums[mid]==key){
            ans=mid;
            break;
        }

        if(nums[mid]>=nums[end]){           //=> from start till mid, array is sorted

            if(nums[mid]>key && nums[start]<=key)
                end = mid-1;
            else
                start = mid+1;

        }else{                              //=> from mid to end, array is sorted

            if(nums[mid]<key  && key<=nums[end])
               start = mid+1;
            else
                end = mid-1;

        }


    }

    return ans;

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t;
    while(t--){

        int n,toSearch; cin>>n;
        int nums[n];

        for(int i=0;i<n;i++)
            cin>>nums[i];
        cin>>toSearch;

        cout<<searchedIndex(nums,toSearch,n)<<endl;


    }

}

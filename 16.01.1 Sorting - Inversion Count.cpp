//https://practice.geeksforgeeks.org/problems/inversion-of-array/0
#include<iostream>
using namespace std;

#define ll long long

ll mergeSort(int* arr, int beg, int end){

    if(beg>=end)
        return 0;

    int mid = (beg+end)/2;

    ll left = mergeSort(arr,beg,mid);
    ll right = mergeSort(arr,mid+1,end);
    ll ans = left+right;

    //Below is the merging part
    int i=beg,j=mid+1,k=beg;

    int temp[end+1];

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else{
            ans+=(mid-i+1);
            temp[k++]=arr[j++];
        }
    }

    while(i<=mid)
        temp[k++] = arr[i++];
    while(j<=end)
        temp[k++] = arr[j++];

    for(int l=beg;l<k;l++)
        arr[l]=temp[l];

    return ans;
}

int main(){

    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        int* arr = new int[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        cout<<mergeSort(arr,0,n-1)<<endl;

    }

}

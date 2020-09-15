#include<iostream>
using namespace std;

void mergeSort(int* arr, int beg, int end){

    if(beg>=end)
        return;

    int mid = (beg+end)/2;

    mergeSort(arr,beg,mid);
    mergeSort(arr,mid+1,end);


    //Below is the merging part
    int i=beg,j=mid+1,k=beg;

    int temp[end+1];

    while(i<=mid && j<=end){
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }

    while(i<=mid)
        temp[k++] = arr[i++];
    while(j<=end)
        temp[k++] = arr[j++];

    for(int l=beg;l<k;l++)
        arr[l]=temp[l];

    return;

}

int main(){

    int n; cin>>n;
    int* arr = new int[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}

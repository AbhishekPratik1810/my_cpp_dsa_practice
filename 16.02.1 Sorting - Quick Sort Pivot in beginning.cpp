#include<iostream>
using namespace std;

void quickSort(int* arr, int start, int end){

    if(start>=end)
        return;

    int left=start+1, right = end, pivot=start;

    while(left<=right){
        if(arr[left]>arr[pivot] && arr[right]<arr[pivot])
            swap(arr[left++],arr[right--]);
        if(arr[left]<=arr[pivot])
            left++;
        if(arr[right]>=arr[pivot])
            right--;
    }

    swap(arr[pivot],arr[right]);                    //We want to swap, and the incoming element MUST BE smaller than pivot as, it is swapped in starting position, and partition property has to be maintained
                                                    //We know, that right>left => right is currently in that part of the array which is smaller than pivot element
                                                    //Hence swap right with pivot
    quickSort(arr,start,right-1);
    quickSort(arr,right+1,end);


}


int main(){


    int n;
    cin>>n;

    int* arr = new int[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];


    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}

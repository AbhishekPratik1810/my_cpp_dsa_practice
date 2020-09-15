//https://practice.geeksforgeeks.org/problems/quick-sort/1
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int partition (int arr[], int start, int end)
{
    int pivot =  end;
    int left = start, right = end-1;

    while(left<=right){
        if(arr[left]>arr[pivot] && arr[right]<arr[pivot])
            swap(arr[left++],arr[right--]);
        if(arr[left]<=arr[pivot])
            left++;
        if(arr[right]>=arr[pivot])
            right--;
    }

    swap(arr[left],arr[pivot]);                     //We want to swap, and the incoming element MUST BE larger than pivot as, it is swapped in ending position, and partition property has to be maintained
                                                    //We know, that right>left => right is currently in that part of the array which is smaller than pivot element
                                                    //Similarly, left in that part of the array which is larger than the pivot element. Hence swap with left

    return left;

}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}




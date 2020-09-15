//https://practice.geeksforgeeks.org/problems/heap-sort/1
#include <bits/stdc++.h>
using namespace std;
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i);
void buildHeap(int arr[], int n);

// main function to do heap sort
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    static int arr[1000001];
    int n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

//O(logn) using sift down approach, this is however big-O(logn) In general for nodes at the bottom of the tree it takes almost constant time O(1)
void heapify(int arr[], int n, int idxCurr)  {
      while(1){
          int idxLeft= 2*idxCurr+1, idxRight = 2*idxCurr+2, idxLargest=idxCurr;
          if(idxLeft<n && arr[idxLeft]>arr[idxLargest])
            idxLargest=idxLeft;
          if(idxRight<n && arr[idxRight]>arr[idxLargest])
            idxLargest=idxRight;
          if(idxCurr!=idxLargest){
            swap(arr[idxCurr],arr[idxLargest]);
            idxCurr=idxLargest;
          }else
            break;

      }

}

//Creating a max heap using heapify  O(nlogn) X (Wrong) O(n) is correct, can be proved by Taylor Series convergence
//O(logn) of heapify is only for the nodes very high up the tree(which are less in number) as compared to those at the bottom.
void buildHeap(int arr[], int n)  {
    for(int i=n-1;i>=0;i--){            //can also start from a non leaf node i.e i=n/2-1
        heapify(arr,n,i);               //NOTE: the 2nd parameter passed is n
    }
}

//Creating a max heap using sift up O(nlogn)
void buildHeapUsingInsertion(int arr[],int n){
    for(int i=0;i<n;i++){
        int idxCurr=i,idxParent=(i-1)/2;
        //This method below runs in O(logn) and as we are sifting up, the nodes at the bottom take O(logn), the nodes at the top take O(1), hence this is inefficient wrt Heapify
        while(idxCurr>0 && arr[idxCurr]>arr[idxParent]){
            swap(arr[idxCurr],arr[idxParent]);
            idxCurr=idxParent;
            idxParent=(idxCurr-1)/2;
        }
    }
}


//https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
#include<bits/stdc++.h>
#define N 105
#define vi vector<int>
using namespace std;

int *mergeKArrays(int arr[][N], int k)
{
    int* res = new int[k*k];

    priority_queue<vi,vector<vi>,greater<vi>> minHeap;

    for(int i=0;i<k;i++)
        minHeap.push({arr[i][0],0,i});


    int currIdx=0,currElement,currRow, currPos=0;
    while(!minHeap.empty()){
        currElement = (minHeap.top())[0];
        currIdx = (minHeap.top())[1];
        currRow = (minHeap.top())[2];
        minHeap.pop();
        res[currPos++]=currElement;

        if(currIdx+1<k)
            minHeap.push({arr[currRow][currIdx+1],currIdx+1,currRow});

    }

    return res;

}

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}



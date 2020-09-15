//https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0

#include <iostream>
#include<queue>
#include<cmath>
using namespace std;

int main() {

	int n; cin>>n;

	double arr[n];

	for(int i=0;i<n;i++)
	    cin>>arr[i];


	if(n==1)
	    cout<<arr[0]<<endl;
	else if(n==2){
	    cout<<arr[0]<<" "<<(int)(arr[0]+arr[1])/2<<endl;
	}else{

	   priority_queue<double> maxHeap;
	   priority_queue<double,vector<double>,greater<double>> minHeap;


	  int mxSize=1, mnSize=1;
	  long long currMedian = (arr[0]+arr[1])/2, toShift ;

	   cout<<arr[0]<<endl<<(int)(arr[0]+arr[1])/2<<endl;

	   if(arr[1]>arr[0]){
	       maxHeap.push(arr[0]);
	       minHeap.push(arr[1]);
	   }else{
	       maxHeap.push(arr[1]);
	       minHeap.push(arr[0]);
	   }


	   for(int i=2;i<n;i++){


	        if(mxSize>mnSize){

	            if(arr[i]>currMedian){
	                minHeap.push(arr[i]);
	            }else{
	                toShift = maxHeap.top();
	                maxHeap.pop();
	                minHeap.push(toShift);
	                maxHeap.push(arr[i]);
	            }

	            currMedian = (minHeap.top()+maxHeap.top())/2;

	        }else if (mxSize==mnSize){

	            if(arr[i]>currMedian){
	                minHeap.push(arr[i]);
	                currMedian = minHeap.top();
	            }else{
	                maxHeap.push(arr[i]);
	                currMedian = maxHeap.top();
	            }

	        }else{

	            if(arr[i]>currMedian){
                    toShift = minHeap.top();
	                minHeap.pop();
	                maxHeap.push(toShift);
	                minHeap.push(arr[i]);
	            }else{
	                maxHeap.push(arr[i]);
	            }

	            currMedian = (minHeap.top()+maxHeap.top())/2;


	        }



	        mxSize = maxHeap.size();
	        mnSize = minHeap.size();
	        cout<<((int)currMedian)<<endl;
	   }

	}

	return 0;
}

#include <iostream>
using namespace std;

void insertInHeap(int arr[], int currPos){

    int parent = currPos/2;

    while(currPos>1 && arr[currPos]>arr[parent]){
        swap(arr[currPos],arr[parent]);
        currPos = parent;
        parent/=2;
    }

}

void heapify(int cIdx, int arr[], int lastIdx){

    int idxL = 2*cIdx;
    int idxR = idxL+1;

    int maxIdx = cIdx;

    if(idxL<=lastIdx && arr[idxL]>arr[cIdx])
        maxIdx = idxL;

    if(idxR<=lastIdx && arr[idxR]>arr[maxIdx])
        maxIdx = idxR;


    if(maxIdx!=cIdx){
        swap(arr[maxIdx],arr[cIdx]);
        heapify(maxIdx,arr,lastIdx);
    }


}


void pop(int arr[], int &heapPosition){

    swap(arr[1],arr[heapPosition--]);

    heapify(1,arr,heapPosition);

}




int main() {
	int t;
	cin>>t;

	while(t--){

	    int n; cin>>n;
	    int arr[n+1];

	    arr[0]=-1;

	    for(int i=1;i<=n;i++)
	        cin>>arr[i];

        //Faster Insertion, O(n)
        for(int i=n/2;i>=1;i--){
            heapify(i,arr,n);
        }
        //Slower Insertion, O(nlogn)
	    /*for(int i=1;i<=n;i++)
	        insertInHeap(arr,i);*/

	    int heapPosition = n;

	    for(int i=1;i<=n;i++)
	        pop(arr,heapPosition);

	    for(int i=1;i<=n;i++)
	        cout<<arr[i]<<" ";

	    cout<<endl;



	}
	return 0;
}

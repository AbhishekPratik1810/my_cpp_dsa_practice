#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n,target,newTarget; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cin>>target;

    sort(arr.begin(),arr.end());


    for(int i=0;i<n;i++){
        int start=i+1, end = n-1,newTarget = target-arr[i];

        while(start<end){
            if(arr[start]+arr[end]==newTarget){
                cout<<arr[i]<<", "<<arr[start]<<" and "<<arr[end]<<endl;
                start++;
                end--;
            }else if(arr[start]+arr[end]>newTarget){
                end--;
            }else
                start++;
        }
    }


}

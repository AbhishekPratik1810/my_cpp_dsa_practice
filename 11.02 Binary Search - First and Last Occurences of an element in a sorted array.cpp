#include<iostream>
#include<climits>
using namespace std;

int main(){

    int t; cin>>t;
    while(t--){
        int n,elt;
        cin>>n>>elt;

        int* arr = new int[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        int start = 1, end = n,mid, first=INT_MAX, last=INT_MAX;

        while(start<=end){
            mid = (start+end)/2;
            if(arr[mid-1]==elt){
                first=mid-1;
                end=mid-1;
            }else if(arr[mid-1]>elt){
                end = mid-1;
            }else
                start=mid+1;
        }

        start = 1, end=n;

        while(start<=end){
            mid = (start+end)/2;
            if(arr[mid-1]==elt){
                last=mid-1;
                start=mid+1;
            }else if(arr[mid-1]>elt){
                end= mid-1;
            }else
                start=mid+1;
        }


        if(first==INT_MAX && last==INT_MAX)
            cout<<-1<<endl;
        else
            cout<<first<<" "<<last<<endl;

    }


}

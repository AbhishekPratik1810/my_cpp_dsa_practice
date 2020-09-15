#include<iostream>
using namespace std;

int main(){


    int n; cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int combined = 0;

    for(int i=0;i<n;i++)
        combined^=arr[i];

    int msbPosition=-1, temp = combined, val1=0;            //MSB Pos starts from -1 as it is 0 based indexing

    while(temp){
        msbPosition++;
        temp>>=1;
    }

    for(int i=0;i<n;i++){
        if(arr[i]&(1<<msbPosition))
            val1^=arr[i];
    }

    cout<<min(val1,val1^combined)<<" "<<max(val1,val1^combined)<<endl;


}

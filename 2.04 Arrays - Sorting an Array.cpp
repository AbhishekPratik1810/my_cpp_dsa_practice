#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];

    for(int i=0;i<n;i++){
        if(i%3==0)
            arr[i]=-1*rand();
        else
            arr[i]=rand();
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

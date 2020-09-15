#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    int max = n-1, min =1;
    int range = max - min +1;
    for(int i=0;i<n;i++){
        if(i%((rand()%range)+min)>2){
            arr[i]=-1*rand();
        }else{
            arr[i]=rand();
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    int m=0,l=n-1;
    while(m<l){
        while(arr[m]<0)
            m++;
        while(arr[l]>=0)
            l--;
        if(m<l)
            swap(arr[m],arr[l]);
    }


    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

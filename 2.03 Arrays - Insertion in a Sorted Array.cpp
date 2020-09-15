#include<iostream>
using namespace std;
int main(){
    int n,elt;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        arr[i]=i*3;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Enter Element to be Added: ";
    cin>>elt;
    int* newArr = new int[n+1];
    for(int i=0;i<n;i++)
        newArr[i]=arr[i];

    //Method 1
    /*int flag=0;
    for(int i=0,j=0;i<n+1;i++){
        if(elt<arr[i] && flag==0){
            newArr[i]=elt;
            flag=1;
        }else{
            newArr[i]=arr[j];
            j++;
        }
    }*/

    //Method 2
    for(int i=n-1;i>=0;i--){
        if(newArr[i]>elt){
            newArr[i+1]=newArr[i];
        }else{
            newArr[i]=elt;
            break;
        }
    }


    arr = newArr;
    for(int i=0;i<n+1;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}

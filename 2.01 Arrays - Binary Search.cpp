#include<iostream>
using namespace std;

int searchForItemRecursion(int arr[], int start,int finish,int key){

    if(start==finish){
        if(arr[start-1]==key)
            return start-1;
        else
            return -1;
    }else{
        if(key > arr[(start+finish)/2 - 1]){
            searchForItemRecursion(arr,(start+finish)/2 + 1,finish,key);
        }else if (key < arr[(start+finish)/2 - 1]){
            searchForItemRecursion(arr,start,(start+finish)/2 -1,key);
        }else{
            return (start+finish)/2 - 1;
        }
    }

}

int searchForItem(int arr[], int n,int key){
    //start and finish are not indices, but the location as seen by a lay-man
    int start =1, finish =n;
    while(start != finish){
        if(key > arr[(start+finish)/2 - 1]){
            start=(start+finish)/2 + 1;
        }else if (key < arr[(start+finish)/2 - 1]){
            finish = (start+finish)/2 -1;
        }else{
            return (start+finish)/2 - 1;
        }
    }
    if(key==arr[start-1])
        return start-1;
    return -1;
}

void displayArray(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int* arr;
    int n,itemLocation;
    cin>>n;
    arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //itemLocation = searchForItem(arr,n,7);
    itemLocation = searchForItemRecursion(arr,1,n,100);
    if(itemLocation == -1){
        cout<<"Item Not Found"<<endl;
    }else{
        cout<<"Item Found At "<<itemLocation<<endl;
    }
    displayArray(arr,n);

    return 0;
}



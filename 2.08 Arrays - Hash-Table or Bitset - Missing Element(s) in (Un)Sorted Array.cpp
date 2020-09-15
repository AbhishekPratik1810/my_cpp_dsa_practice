//Finding missing element(s) in unsorted array

#include <iostream>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    int* arr1 = new int[n];

    //Let code take care of itself to generate random numbers for testing. This gives a sorted sequence
    int rand1 = rand()%(n-1);
    int rand2 = rand()%(9);
    for(int i=0,j=1;i<n;i++,j++){
        if(i%rand1==0){
            j=j+3;
            arr1[i]=j;
        }else if(i%rand2==0){
            arr1[i]=++j;
        }else{
            arr1[i]=j;
        }
    }

    for(int i=0;i<n;i++)
        cout<<arr1[i]<<" ";
    cout<<endl;

    //This gives unsorts the above sorted array
    for(int i=0;i<rand1;i++){
        swap(arr1[i],arr1[rand2]);
        rand2 = rand()%(n-1);
    }

    for(int i=0;i<n;i++)
        cout<<arr1[i]<<" ";
    cout<<endl;

    int max=0,min=arr1[0];
    for(int i=0;i<n;i++){
        if(arr1[i]>max)
            max=arr1[i];
        if(arr1[i]<min)
            min = arr1[i];
    }

    int* arr2 = new int[max-min+1];
    for(int i=0;i<(max-min+1);i++)
        arr2[i]=-1;

    for(int i=0;i<n;i++){
        arr2[arr1[i]-min]=arr1[i];
    }
    for(int i=0;i<(max-min+1);i++)
        cout<<arr2[i]<<" ";
    cout<<endl;

    for(int i=0;i<(max-min+1);i++){
        if(arr2[i]==-1)
            cout<<"Missing Element "<<i+min<<endl;
    }
}

int32_t main(){
    solve();

}

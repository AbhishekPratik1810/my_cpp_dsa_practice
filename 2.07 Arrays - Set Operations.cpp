#include <bits/stdc++.h>

using namespace std;
// #define int long long


//Time Complexity: O(n^2 + m^2)
void union1(int arr1[], int arr2[], int n, int m){

    //Assuming arr1, arr2 both have unique elements wrt their arrays respectively
    int* arrU = new int[n+m];
    for(int i=0;i<n;i++){
        arrU[i]=arr1[i];
    }
    int length = n;
    for(int i=0;i<m;i++){
            bool duplicate = false;
            for(int k=0;k<length;k++){
                if(arr2[i]==arrU[k]){
                    cout<<"Discarding Duplicate "<<arr2[i]<<endl;
                    duplicate=true;
                }
            }
            if(!duplicate){
                arrU[length]=arr2[i];
                length++;
            }
    }

    sort(arrU,arrU+length);

    for(int i=0;i<length;i++)
        cout<<arrU[i]<<" ";
    cout<<endl;
}

//Time Complexity: Theta(n + m) if already sorted array (Use merging 2 sorted arrays principle)
void union2(int arr1[],int arr2[],int n, int m){

    sort(arr1,arr1+n);
    sort(arr2,arr2+m);

    //Union Calculation Begins here
    int length = 0;
    int i=0,j=0;
    int* arrU = new int[n+m];

    while(i<n || j<m){

        while(i<n && arr1[i]==arr1[i+1])
            i++;
        while(j<m && arr2[j]==arr2[j+1])
            j++;


        if(i<n && j<m){
            if(arr1[i]==arr2[j]){
                arrU[length]=arr1[i];
                i++;
                j++;
            }else if(arr1[i]>arr2[j]){
                arrU[length]=arr2[j];
                j++;
            }else{
                arrU[length]=arr1[i];
                i++;
            }
        }else if(j<m){
            arrU[length]=arr2[j];
            j++;
        }else{
            arrU[length]=arr1[i];
            i++;
        }

        length++;


    }
    for(int i=0;i<length;i++)
        cout<<arrU[i]<<" ";
    cout<<endl;
}


//Time Complexity O(m*n)
void intersection(int arr1[], int arr2[], int n, int m){
    int* low=arr1;
    int* high=arr2;
    int l=n,h=m;
    if(n>m){
        l=m;
        h=n;
        low = arr2;
        high = arr1;
    }
    int* arrInt = new int[n+m];
    int length = 0;
    for(int i=0;i<l;i++){
        for(int j=0;j<h;j++){
            if(low[i]==high[j]){
                arrInt[length]=low[i];
                length++;
            }
        }
    }
    for(int i=0;i<length;i++)
        cout<<arrInt[i]<<" ";
    cout<<endl;
}

//Time Complexity Theta(m+n) if arrays are already sorted (Use merging 2 sorted arrays principle)
void intersection2(int arr1[],int arr2[], int n, int m){
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);

    //Union Calculation Begins here
    int length = 0;
    int i=0,j=0;
    int* arrInt = new int[n+m];

    while(i<n || j<m){

        while(i<n && arr1[i]==arr1[i+1])
            i++;
        while(j<m && arr2[j]==arr2[j+1])
            j++;


        if(i<n && j<m){
            if(arr1[i]==arr2[j]){
                arrInt[length]=arr1[i];
                i++;
                j++;
                length++;
            }else if(arr1[i]>arr2[j]){
                j++;
            }else{
                i++;
            }
        }else if(j<m){
            j++;
        }else{
            i++;
        }


    }
    for(int i=0;i<length;i++)
        cout<<arrInt[i]<<" ";
    cout<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    int* arr1 = new int[n];
    int* arr2 = new int[m];

    int max1 = n-1,max2 = m-1, min =1;
    int range1 = max1 - min +1;
    int range2 = max2 - min +1;
    for(int i=0;i<n;i++){
        if(i%((rand()%range1)+min)>10){
            arr1[i]=-1*(rand()%100);
        }else{
            arr1[i]=(rand()%100);
        }
    }
    for(int i=0;i<m;i++){
        if(i%((rand()%range2)+min)>10){
            arr2[i]=-1*(rand()%100);
        }else{
            arr2[i]=(rand()%100);
        }
    }

    for(int i=0;i<n;i++)
        cout<<arr1[i]<<" ";
    cout<<endl;

    for(int i=0;i<m;i++)
        cout<<arr2[i]<<" ";
    cout<<endl;

    union1(arr1,arr2,n,m);
    union2(arr1,arr2,n,m);
    intersection(arr1,arr2,n,m);

    /*for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr1[j]>arr1[j+1])
                swap(arr1[j],arr1[j+1]);
        }
    }

    for(int i=m-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr2[j]>arr2[j+1])
                swap(arr2[j],arr2[j+1]);
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr1[i]<<" ";
    cout<<endl;

    for(int i=0;i<m;i++)
        cout<<arr2[i]<<" ";
    cout<<endl;*/
}

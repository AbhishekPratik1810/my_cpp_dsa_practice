//https://www.geeksforgeeks.org/count-number-subarrays-given-xor/

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    int n,k; cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cin>>k;

    int prefixXor[n];
    prefixXor[0]=arr[0];

    for(int i=1;i<n;i++)
        prefixXor[i]=prefixXor[i-1]^arr[i];

    unordered_map<int,int> prevCount;
    prevCount[0]=1;

    int answer=0;

    for(int i=0;i<n;i++){

        int toFind = k^prefixXor[i];

        if(prevCount[toFind])                    //previously k^prefixXor[i] exisited, let it be till j => from 0-j prefixXor = prev, from 0-i prefixXor = currXor => there exists a subarray between j+1-i whose xor is k
            answer+=prevCount[toFind];

        prevCount[prefixXor[i]]++;

    }

    cout<<answer<<endl;

}

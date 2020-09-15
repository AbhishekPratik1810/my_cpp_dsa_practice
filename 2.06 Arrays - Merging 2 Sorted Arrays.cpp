//https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays/0

#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        int n,m; cin>>n>>m;

        int first[n];
        int second[m];

        for(int i=0;i<n;i++)
            cin>>first[i];

        for(int i=0;i<m;i++)
            cin>>second[i];

        int firstPtr=n-1, secondPtr=0;

        while(firstPtr>=0 && secondPtr<m && first[firstPtr]>=second[secondPtr])
            swap(first[firstPtr--],second[secondPtr++]);


        sort(first,first+n);
        sort(second,second+m);

        for(int i=0;i<n;i++)
            cout<<first[i]<<" ";

        for(int i=0;i<m;i++)
            cout<<second[i]<<" ";

        cout<<endl;


    }
}

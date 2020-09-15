//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages/0
#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

#define ll long long

ll maxPossible = 1e18;

bool possible(ll currPages, int pages[], int books, int students){


    for(int i=0;i<books;i++)
        if(pages[i]>currPages)
            return 0;

    int currCount=1,cSum=pages[0];

    for(int i=1;i<books;i++){

        if(pages[i]+cSum>currPages){
            currCount++;
            cSum=pages[i];
        }else
            cSum+=pages[i];
    }

    return currCount<=students;

}


ll minPages(int pages[], int books, int students){

    if(students>books)
        return -1;

    ll start = pages[0], end = 0, ans = maxPossible, mid ;

    for(int i=0;i<books;i++){
        start = min(start,(ll)pages[i]);
        end+=pages[i];
    }

    while(start<=end){

        mid = start + (end-start)/2;

        if(possible(mid,pages,books,students)){
            ans = min(ans,mid);
            end = mid-1;
        }else{
            start = mid+1;
        }

    }

    return ans;


}

int main(){

    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);


    int t; cin>>t;

    while(t--){

        int n,students;
        cin>>n;

        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        cin>>students;

        cout<<minPages(arr,n,students)<<endl;

    }

}

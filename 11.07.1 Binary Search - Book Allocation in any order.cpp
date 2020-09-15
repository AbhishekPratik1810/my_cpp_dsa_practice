#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

#define ll long long

ll maxPossible = 1e18;

bool possible(ll currPages, int pages[], int books, int students){

    //Create buckets which will be equal to the count of students, occupying the maximum pages from end, then keep adding the remaining pages one by one to each bucket
    vector<ll> bucket;

    for(int i=books-students;i<books;i++)
        bucket.push_back(pages[i]);

    int bIdx=0;
    for(int i=books-students-1;i>=0;i--){
        bucket[bIdx++]+=pages[i];
        bIdx%=(bucket.size());
    }

    for(auto i : bucket)
        if(i>currPages)
            return 0;

    return 1;



}


ll minPages(int pages[], int books, int students){

    if(students>books)
        return -1;

    ll start = pages[0], end = 0, ans = maxPossible, mid ;

    for(int i=0;i<books;i++)
        end+=pages[i];

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

        sort(arr,arr+n);

        cout<<minPages(arr,n,students)<<endl;

    }

}

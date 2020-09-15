#include <iostream>
#include <deque>
using namespace std;


int main() {

    int t; cin>>t;

    while(t--){
        int n,k; cin>>n>>k;
        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        deque<int> dq;

        for(int i=0;i<k;i++){

            //Anything recently added which is less than me is worthless. Addition happens at end => Deletion of worthless elements happen at end
            while(!dq.empty() && arr[dq.back()]<arr[i])
                dq.pop_back();

            dq.push_back(i);

        }


        for(int i=k;i<n;i++){

            cout<<arr[dq.front()]<<" ";

            while(!dq.empty() && dq.front()<=i-k)
                dq.pop_front();

            while(!dq.empty() && arr[dq.back()]<arr[i])
                dq.pop_back();

            dq.push_back(i);

        }

        cout<<arr[dq.front()]<<endl;




    }

	return 0;
}

#include <iostream>
#include<queue>
using namespace std;

int main() {

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        priority_queue<int,vector<int>,greater<int>> pq;

        for(int i=0;i<n;i++)
            pq.push(arr[i]);

        if(n==1)
            cout<<0<<endl;
        else{

            int operations = n-1;

            int minA,minB;
            long long totalCost = 0;
            for(int i=1;i<=n-1;i++){
                minA = pq.top(); pq.pop();
                minB = pq.top(); pq.pop();

                totalCost+=minA+minB;

                pq.push(minA+minB);

            }

            cout<<totalCost<<endl;

        }



    }


	return 0;
}

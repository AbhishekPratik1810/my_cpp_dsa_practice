#include <iostream>
#include <stack>
#include <vector>
using namespace std;


void nearestSmallestRight(int *arr, int n){

    vector<int> nearestSmallest(n);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        if(st.empty())
            nearestSmallest[i]=-1;
        else{

            while(!st.empty() && st.top()>=arr[i])
                st.pop();

            nearestSmallest[i] = st.empty() ? -1 : st.top();

        }

        st.push(arr[i]);
    }

    for(auto i : nearestSmallest)
        cout<<i<<" ";

    cout<<endl;

}

int main() {



    int n; cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    nearestSmallestRight(arr,n);

	return 0;
}

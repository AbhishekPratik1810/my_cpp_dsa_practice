#include <iostream>
#include <stack>
#include <vector>
using namespace std;


void nearestSmallestLeft(int *arr, int n){

    vector<int> nearestSmallest(n);
    stack<int> st;

    for(int i=0;i<n;i++){
        if(st.empty())
            nearestSmallest[i]=-1;
        else{

            while(!st.empty() && st.top()>=arr[i])          //If I find something greater than me, then that can never be nearest smallest
                st.pop();

            if(st.empty())
                nearestSmallest[i]=-1;
            else
                nearestSmallest[i]=st.top();
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

    nearestSmallestLeft(arr,n);

	return 0;
}

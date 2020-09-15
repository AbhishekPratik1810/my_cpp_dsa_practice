#include<iostream>
#include<stack>
#include<vector>
using namespace std;


void nearestGreaterLeft(int arr[], int n){

   vector<int> nearestGreater(n);
   stack<int> st;

   for(int i=0;i<n;i++){
        if(st.empty()){
            nearestGreater[i]=-1;
            st.push(arr[i]);
        }else{

            while(!st.empty() && st.top()<=arr[i])
                st.pop();

            if(st.empty())
                nearestGreater[i]=-1;
            else
                nearestGreater[i]=st.top();

            st.push(arr[i]);


        }
   }

   for(auto i : nearestGreater)
        cout<<i<<" ";
   cout<<endl;

}


int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    nearestGreaterLeft(arr,n);
}




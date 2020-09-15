//https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0
#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n; cin>>n;
        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        vector<int> firstSmallLeft(n);
        vector<int> lastSmallRight(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            if(st.empty())
                firstSmallLeft[i]=-1;
            else{
                while(!st.empty() && arr[st.top()]>=arr[i])
                    st.pop();
                if(st.empty())
                    firstSmallLeft[i]=-1;
                else
                    firstSmallLeft[i]=st.top();
            }
            st.push(i);
        }

        while(!st.empty())
            st.pop();

        for(int i=n-1;i>=0;i--){
            if(st.empty())
                lastSmallRight[i]=n;
            else{
                while(!st.empty() && arr[st.top()]>=arr[i])
                    st.pop();
                if(st.empty())
                    lastSmallRight[i]=n;
                else
                    lastSmallRight[i]=st.top();
            }
            st.push(i);
        }

        int ans = 0;

        for(int i=0;i<n;i++)
            ans = max(ans, arr[i]*(lastSmallRight[i]-firstSmallLeft[i]-1));

        cout<<ans<<endl;

    }


}


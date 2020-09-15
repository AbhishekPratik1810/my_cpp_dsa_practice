//https://practice.geeksforgeeks.org/problems/max-rectangle/1/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}

int lah(vector<int> &arr, int n){

    stack<int> st;
    vector<int> firstSmallLeft(n);
    vector<int> lastSmallRight(n);
    int ans =0;

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



    for(int i=0;i<n;i++)
        ans = max(ans, arr[i]*(lastSmallRight[i]-firstSmallLeft[i]-1));

    return ans;

}


int maxArea(int M[MAX][MAX], int n, int m) {

    vector<int> arr(m,0);


    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j])
                arr[j]+=1;
            else
                arr[j]=0;
        }

        ans = max(ans, lah(arr,m));

    }

    return ans;


}

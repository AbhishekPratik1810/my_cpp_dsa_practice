//https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0
#include<iostream>
using namespace std;

#define ll long long

ll dp[101][101];

ll mcmCost(int start, int end, int arr[]){

    if(start+1==end)
        return 0;

    if(dp[start][end]!=-1) return dp[start][end];

    ll minCost = 1e18, currCost;

    for(int i=start+1;i<end;i++){

        currCost = mcmCost(start,i,arr) + mcmCost(i,end,arr) + arr[start]*arr[end]*arr[i];               //i is the pivot, which will go from 1 to m-1, m is total matrices(i.e 4 if arr size = 5)
        minCost = min(minCost,currCost);

    }
    return dp[start][end] = minCost;


    /*
        Consider A B C D, and arr[] = 10 20 30 40 50

        (A)*(BCD)
        (AB)*(CD)
        (ABC)*(D)

        No of pivots = no of matrices - 1, hence, i goes from start+1 to end-1
    */

}



int main(){

    int t; cin>>t;

    while(t--){


        int n;
        cin>>n;

        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;

        cout<<mcmCost(0,n-1,arr)<<endl;

    }



}

/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int memo[101][101];

//1 based indexing
int mcm(int from, int to, vector<int> &nums){
    if(from==to)
        return 0;
    if(memo[from][to]) return memo[from][to];
    int minCost=INT_MAX;
    for(int curr=from;curr<to;curr++){
        int intermediateAns = mcm(from,curr,nums) + mcm(curr+1,to,nums) + nums[from-1]*nums[curr]*nums[to];
        minCost=min(minCost,intermediateAns);
    }
    return memo[from][to] = minCost;
}

int bottomUp(vector<int> &nums){
    int dp[101][101] = {0};                     //dp[i][j] : MCM for Ai.Ai+1...Aj
    int matrices = nums.size()-1;

    //A1A2A3..AM   = (A1.A2..AK).(AK+1,AK+2...AM)

    //to be filled diagonally
    for(int diff=1;diff<matrices;diff++){

        for(int j=1+diff;j<=matrices;j++){

            int i=j-diff;
            int best=INT_MAX;

            for(int k=i;k<j;k++){
                int intermediate = dp[i][k]+dp[k+1][j]+ nums[i-1]*nums[k]*nums[j];
                best=min(best,intermediate);
            }

            dp[i][j]=best;
        }
    }

    return dp[1][matrices];


}

int main(){
    int t; cin>>t;
    while(t--){
        int n;  cin>>n;
        vector<int> nums(n);                    //nums has size n => actually n-1 matrices
        for(int i=0;i<n;i++) cin>>nums[i];
        for(int i=0;i<101;i++)
            for(int j=0;j<101;j++)
                memo[i][j]=0;
        cout<<mcm(1,n-1,nums)<<endl;
        cout<<bottomUp(nums)<<endl;
    }
}
*/

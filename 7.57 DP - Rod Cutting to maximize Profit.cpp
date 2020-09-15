//https://practice.geeksforgeeks.org/problems/cutted-segments/0
#include <iostream>
using namespace std;

int dp[4001];

int ans(int length, int wt[]){

    if(length<0)
        return -1e9;
    if(length == 0)
        return 0;


    if(dp[length]!=-1) return dp[length];

    int best = -1e9, currProfit = 0;

    for(int i=0;i<=2;i++){
        currProfit = 1 + ans(length-wt[i],wt);
        best = max(best,currProfit);
    }

    return dp[length] = best;



}


int main() {

	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    int wt[3];
	    cin>>wt[0]>>wt[1]>>wt[2];


	    for(int i=0;i<=4000;i++)
	        dp[i]=-1;

	    int ans1 = ans(n,wt);


	    cout<< (ans1 == (int) -1e9? 0 : ans1) <<endl;

	}

	return 0;
}



/*
int dp[4000][3];

int ans(int length, int wt[], int end){

    if(end==-1)
        return -1e9;
    if(length == 0)
        return 0;

    if(dp[length][end]!=-1)  return dp[length][end];

    if(wt[end]>length)
        return dp[length][end] = ans(length,wt,end-1);
    else
        return dp[length][end] = max(1 + ans(length-wt[end],wt,end) ,
                                         ans(length,wt,end-1));

}


int main() {

	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    int wt[3];
	    cin>>wt[0]>>wt[1]>>wt[2];

	    for(int i=0;i<=n;i++)
	        for(int j=0;j<3;j++)
	            dp[i][j] = -1;
	    int ans1 = ans(n,wt,2);

	    cout<< (ans1==-1 ? 0 : ans1);

	}

	return 0;
}
*/

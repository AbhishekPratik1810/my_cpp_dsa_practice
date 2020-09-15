//https://practice.geeksforgeeks.org/problems/minimum-points-to-reach-destination/0
#include <iostream>
using namespace std;


int main() {


	int t; cin>>t;

	while(t--){

        int row,col;
	    cin>>row>>col;

        int matrix[row][col];

	    for(int i=0;i<row;i++)
	        for(int j=0;j<col;j++)
	            cin>>matrix[i][j];


        int dp[row][col];

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                dp[i][j]=0;

        dp[row-1][col-1] = matrix[row-1][col-1]>0? 1 : abs(matrix[row-1][col-1])+1;

        for(int j=col-2;j>=0;j--)
            dp[row-1][j] = matrix[row-1][j]-dp[row-1][j+1]>=0 ? 1 : dp[row-1][j+1]-matrix[row-1][j];

        for(int i=row-2;i>=0;i--)
            dp[i][col-1] = matrix[i][col-1]-dp[i+1][col-1]>=0 ? 1 : dp[i+1][col-1] - matrix[i][col-1];


        for(int i=row-2;i>=0;i--){
            for(int j=col-2;j>=0;j--){

                int intermediate = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = matrix[i][j] - intermediate >=0 ? 1 : intermediate-matrix[i][j];

            }
        }

        cout<<dp[0][0]<<endl;

	}




	return 0;
}

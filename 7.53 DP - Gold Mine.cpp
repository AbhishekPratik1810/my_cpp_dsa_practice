//https://practice.geeksforgeeks.org/problems/gold-mine-problem/0

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int row,col;

int dp[21][21];

bool isInColLimits(int cCol){
    return (cCol>=0 && cCol<col);
}

bool isInRowLimits(int cRow){
    return (cRow>=0 && cRow<row);
}

int compute(int cRow,int cCol, vector<vector<int>> &field){

    if(!isInColLimits(cCol+1))
        return field[cRow][cCol];

    if(dp[cRow][cCol]!=-1) return dp[cRow][cCol];

    int res=field[cRow][cCol];

    int takingRight = compute(cRow,cCol+1,field);

    //If Diagonally Upward Movement Possible
    if(isInRowLimits(cRow-1))
        takingRight=max(takingRight,compute(cRow-1,cCol+1,field));

    //If Diagonally Downward Movement Possivle
    if(isInRowLimits(cRow+1))
        takingRight=max(takingRight,compute(cRow+1,cCol+1,field));

    return dp[cRow][cCol] = res+takingRight;

}

int main(){

    int t; cin>>t;
    while(t--){

        cin>>row>>col;
        vector<vector<int>> field(row,vector<int>(col));

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                cin>>field[i][j];

        int maxMoney=INT_MIN;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                dp[i][j]=-1;
            }
        }

        for(int i=0;i<row;i++)
            maxMoney=max(maxMoney,compute(i,0,field));

        cout<<maxMoney<<endl;

    }


}

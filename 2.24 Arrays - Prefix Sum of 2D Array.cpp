#include<iostream>
#include<cstring>
using namespace std;

int main() {

    int row,col; cin>>row>>col;
    int matrix[row][col];
    int prefixSum[row][col];

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>matrix[i][j];



    for(int i=row-1;i>=0;i--){
        prefixSum[i][col-1]=matrix[i][col-1];
        for(int j=col-2;j>=0;j--){
            prefixSum[i][j]=prefixSum[i][j+1]+matrix[i][j];
        }
    }

    for(int j=col-1;j>=0;j--){
        for(int i=row-2;i>=0;i--){
            prefixSum[i][j]+=prefixSum[i+1][j];
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cout<<prefixSum[i][j]<<" ";
        cout<<endl;
    }



	return 0;
}

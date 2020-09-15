#include<iostream>
using namespace std;

int main(){

    int row,col; cin>>row>>col;
    int matrix[row][col];

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>matrix[i][j];

    int startRow=0,startCol=0,endRow=row-1,endCol=col-1;

    while(startRow<=endRow && startCol<=endCol){

        for(int i=startRow;i<=endRow;i++)
            cout<<matrix[i][startCol]<<", ";
        startCol++;

        for(int j=startCol;j<=endCol;j++)
            cout<<matrix[endRow][j]<<", ";
        endRow--;

        if(startCol<=endCol){
            for(int i=endRow;i>=startRow;i--)
                cout<<matrix[i][endCol]<<", ";
            endCol--;
        }
        if(startRow<=endRow){
            for(int j=endCol;j>=startCol;j--)
                cout<<matrix[startRow][j]<<", ";
            startRow++;
        }
    }
    cout<<"END"<<endl;

}

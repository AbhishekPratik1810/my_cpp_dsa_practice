//https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0

#include<iostream>
using namespace std;

int unmask(int cRow,int cCol, int col){
    return cRow*col+cCol+1;
}

int main(){

    int t; cin>>t;
    while(t--){

        int row,col; cin>>row>>col;

        int matrix[row][col];

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                cin>>matrix[i][j];

        int startRow=0, startCol=0, endRow=row-1, endCol = col-1;

        while(startRow<=endRow && startCol<=endCol){

            for(int j=startCol;j<=endCol;j++)
                cout<<matrix[startRow][j]<<" ";
            startRow++;

            for(int i=startRow;i<=endRow;i++)
                cout<<matrix[i][endCol]<<" ";
            endCol--;

            if(endRow>=startRow){                       //Note startRow has already been incremented. We have to call this, only when endRow>(origStartRow) hence the >=
                for(int j=endCol;j>=startCol;j--)
                    cout<<matrix[endRow][j]<<" ";
                endRow--;
            }
            if(endCol>=startCol){
                for(int i=endRow;i>=startRow;i--)
                    cout<<matrix[i][startCol]<<" ";
                startCol++;
            }

        }
        cout<<endl;
/*
        int cRStart=0, cREnd=row-1, cCStart=0, cCEnd=col-1;

        bool vis[row*col+1]={};

        while(cRStart<row || cCStart<col){

            if(cRStart<row){
                for(int c=cCStart;c<=cCEnd;c++){
                    if(!vis[unmask(cRStart,c,col)]){
                        cout<<matrix[cRStart][c]<<" ";
                        vis[unmask(cRStart,c,col)]=1;
                    }
                }
            }

            if(cCEnd>=cCStart){
                for(int r=cRStart;r<=cREnd;r++){
                    if(!vis[unmask(r,cCEnd,col)]){
                        cout<<matrix[r][cCEnd]<<" ";
                        vis[unmask(r,cCEnd,col)]=1;
                    }
                }
            }

            if(cREnd>=cRStart){
                for(int c=cCEnd;c>=cCStart;c--){
                    if(!vis[unmask(cREnd,c,col)]){
                        cout<<matrix[cREnd][c]<<" ";
                        vis[unmask(cREnd,c,col)]=1;
                    }
                }
            }
            if(cCStart<col){
                for(int r=cREnd;r>=cRStart;r--){
                    if(!vis[unmask(r,cCStart,col)]){
                        cout<<matrix[r][cCStart]<<" ";
                        vis[unmask(r,cCStart,col)]=1;
                    }
                }
            }



            cRStart++;
            cREnd--;
            cCStart++;
            cCEnd--;

        }
        cout<<endl;
*/

    }

}



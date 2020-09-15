//https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/0
#include<iostream>
#include<vector>
using namespace std;

int row,col;

void floodFill(vector<vector<int>> &matrix, int x,int y,int c,int prev){


    if(x<0 || y<0 || x>=row || y>=col || matrix[x][y]!=prev)
        return;

    matrix[x][y]=c;

    floodFill(matrix,x+1,y,c,prev);
    floodFill(matrix,x-1,y,c,prev);
    floodFill(matrix,x,y+1,c,prev);
    floodFill(matrix,x,y-1,c,prev);

}

int main(){
    int t; cin>>t;
    while(t--){
        int x,y,c; cin>>row>>col;
        vector<vector<int>> matrix(row,vector<int> (col));
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                cin>>matrix[i][j];
        cin>>x>>y>>c;

        floodFill(matrix,x,y,c,matrix[x][y]);

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }

}

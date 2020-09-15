//https://practice.geeksforgeeks.org/problems/n-queen-problem/0
//An upper bound is O(n!) for sure, but exact complexity, we don't know
#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isPossible(int row, int col, int n,  vector<vector<int>> &board){


    //Left Right
    for(int i=1;i<=n;i++)
        if(i!=col && board[row][i])
            return false;

    //Up Down
    for(int i=1;i<=n;i++)
        if(i!=row && board[i][col])
            return false;

    //Left Up                               //Right Down is redundant calculation, as it hasn't been computed yet, 135 degree diagonal
    int i=row-1, j = col-1;

    while(i>=1 && j>=1)
        if(board[i--][j--])
            return false;

    //Left Down                             //Right Up is redundant calculation, 45 degree diagonal
    i=row+1, j = col-1;

    while(i<=n && j>=1)
        if(board[i++][j--])
            return false;

    return true;

}


bool ok;

void printAnswer(int n,vector<vector<int>> &board){

    cout<<"[";
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++)
            if(board[i][j])
                cout<<i<<" ";

    }
    cout<<"] ";

}

void nQueens(int col, int n,vector<vector<int>> &board){

    if(col==n+1){
        printAnswer(n,board);
        ok = 1;
        return;
    }
    for(int i=1;i<=n;i++){
        if(isPossible(i,col,n,board)){
            board[i][col]=1;
            nQueens(col+1,n,board);
            board[i][col]=0;
        }
    }


}


int main(){

    int t; cin>>t;

    while(t--){

        int n; cin>>n;

        vector<vector<int>> board(n+1, vector<int> (n+1,0));
        ok=0;

        nQueens(1,n,board);
        if(!ok)
            cout<<-1;
        cout<<endl;

    }

}



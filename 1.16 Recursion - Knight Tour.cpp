//https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/?ref=lbp
//https://www.codesdope.com/course/algorithms-knights-tour-problem/
//Time Complexity O(8^(n*n))
#include<bits/stdc++.h>

using namespace std;


int dCol[] = { 2, 1, -1, -2, -2, -1, 1, 2 };            //Tried and tested Order, it matters!
int dRow[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int n;
int maxVal;

bool isPossible(int row, int col, vector<vector<int>> &board){
    return row>=0 && row<n && col>=0 && col<n && board[row][col]==-1;
}


bool knightTour(int row, int col, vector<vector<int>> &board,int currPos){

    board[row][col]=currPos;

    if(currPos==maxVal){

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]<=9)
                    cout<<" "<<board[i][j]<<" ";
                else
                    cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }

        return true;
    }

    for(int i=0;i<8;i++)
        if(isPossible(row+dRow[i],col+dCol[i],board) && knightTour(row+dRow[i],col+dCol[i],board,currPos+1))
            return true;


    board[row][col]=-1;
    return false;


}


int main(){

    cin>>n;

    maxVal = n*n-1;

    vector<vector<int>> board(n,vector<int> (n,-1));

    knightTour(0,0,board,0);


}

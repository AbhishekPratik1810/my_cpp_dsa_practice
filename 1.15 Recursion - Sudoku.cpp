//https://practice.geeksforgeeks.org/problems/solve-the-sudoku/0/
/*

    For each empty cell, there are 9 possibilities
    For each possibility, there are (9*9-1) empty cells in the worst case

    For 1 cell, it is 9
    For 2 cells, it is 9 for first, 9 for each of the second with one of the numbers of first, i.e 9*9
    For 3 cells, it is 9*9*9

    Worst, case, there are N^2 empty cells
    => 9*9*9*9*.......(9) N^2 times
    => 9^(N^2)


    Unlike previous backtracking problems, where we had to explore all paths, here, as soon as we find a solution, we return back, and STOP exploring
    If we don't, then the earth will finish, but the program will still go on.

    For example, for 45 empty cells, it would take 2.7676191* 10^(29) years to solve the problem!

*/

#include<iostream>
using namespace std;


bool possible(int row, int col, int sudoku[9][9], int num){

    for(int i=0;i<9;i++)
        if(sudoku[i][col]==num)
            return 0;

    for(int i=0;i<9;i++)
        if(sudoku[row][i]==num)
            return 0;

    int rBegin = (row/3)*3, cBegin = (col/3)*3;

    int rEnd = rBegin+3, cEnd = cBegin+3;

    for(int i=rBegin;i<rEnd;i++){
        for(int j=cBegin;j<cEnd;j++){
            if(sudoku[row][col]==num)
                return 0;
        }
    }

    return 1;


}

bool solve(int row, int col, int sudoku[9][9]){

    if(row == 8 && col == 9){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                cout<<sudoku[i][j]<<" ";
            cout<<endl;
        }

        return true;
    }

    if(col==9)
        return solve(row+1,0,sudoku);

    if(sudoku[row][col])
        return solve(row,col+1,sudoku);



    for(int k=1;k<=9;k++){

        if(possible(row,col,sudoku,k)){
            sudoku[row][col]=k;
            if (solve(row,col+1,sudoku))
                return true;

        }
    }

    sudoku[row][col]=0;
    return false;

}


int main(){


    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t; cin>>t;

    while(t--){

        int sudoku[9][9];

        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                cin>>sudoku[i][j];

        solve(0,0,sudoku);



    }



}

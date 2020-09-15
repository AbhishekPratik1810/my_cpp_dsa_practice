#include<iostream>
using namespace std;

#define maxQueens 20
#define maxSum 40

bool leftUp[maxSum]={}, leftDown[maxSum]={}, occupiedRow[maxQueens]={};                        //Column taken care of by default, as we are incrementing col by 1 in next insertion

bool possible(int row, int col, int queens){
    return !occupiedRow[row] && !leftDown[row+col] && !leftUp[row-col+queens];
}

int nQueens(int col, int queens){

    if(col==queens)
        return 1;

    int total = 0;

    for(int row=0;row<queens;row++){

        if(possible(row,col,queens)){
            occupiedRow[row] = leftDown[row+col] = leftUp[row-col+queens] = 1;
            total+=nQueens(col+1,queens);
            occupiedRow[row] = leftDown[row+col] = leftUp[row-col+queens] = 0;
        }

    }

    return total;


}


int main(){

    int n; cin>>n;
    cout<<nQueens(0,n)<<endl;

}

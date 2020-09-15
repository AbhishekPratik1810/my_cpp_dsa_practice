//https://practice.geeksforgeeks.org/problems/minimum-points-to-reach-destination/0

#include <iostream>
using namespace std;

int row, col;
int matrix[101][101];
bool vis[101][101];

bool isValid(int cRow, int cCol, int points){

    return cRow>=0 && cRow<row && cCol>=0 && cCol<col && !vis[cRow][cCol] && points+ matrix[cRow][cCol]>=1;

}


bool possible(int points,int cRow, int cCol){

    vis[cRow][cCol]=1;

    points+=matrix[cRow][cCol];

    if(points<=0)
        return false;

    if(cRow==row-1 && cCol==col-1)
        return true;

    if(isValid(cRow,cCol+1,points)){
        if(possible(points,cRow,cCol+1))
            return true;
    }


    if(isValid(cRow+1,cCol,points)){
        if(possible(points,cRow+1,cCol))
            return true;
    }

    vis[cRow][cCol]=0;
    return false;

}



int main() {


	int t; cin>>t;

	while(t--){

	    cin>>row>>col;

	    for(int i=0;i<row;i++)
	        for(int j=0;j<col;j++){
	            cin>>matrix[i][j];
	            vis[i][j]=0;
	        }



	    int start = 1, end = 1e7;
	    int ans = 1e7;


	    while(start<=end){

	        int mid = start+(end-start)/2;

            for(int i=0;i<row;i++)
                for(int j=0;j<col;j++)
                    vis[i][j]=0;

	        if(possible(mid,0,0)){
	            ans = min(ans,mid);
	            end = mid-1;
	        }else{
	            start = mid+1;
	        }
	    }




	    cout<<ans<<endl;


	}




	return 0;
}

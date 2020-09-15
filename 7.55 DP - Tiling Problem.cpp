//https://practice.geeksforgeeks.org/problems/number-of-ways/0
//I am considering to fill a 4xN grid, as ans will be equivalent
#include <iostream>
using namespace std;

long long dp[81]={};

long long tile(int width){

    if(width<=0)
        return 0;
    if(width<4)
        return 1;
    if(width==4)
        return 2;

    if(dp[width]) return dp[width];

    long long alongWidth  =   tile(width-4);                    //using 1x4
    long long alongHeight =   tile(width-1);                    //using 4x1


    return dp[width] = alongWidth + alongHeight;

}


int main() {
	int t; cin>>t;

	while(t--){
	    int n; cin>>n;
	    cout<<tile(n)<<endl;
	}

	return 0;
}

#include<iostream>
#include<climits>
using namespace std;

int cost[12][12];
int visitedAll;
int n;
int dp[4097][12];
int MAX=1777;
/*
1
5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
*/

/*
1
5
0 100 1 7777 500
100 0 200 1 7777
1 200 0 300 7777
7777 1 300 0 400
500 7777 7777 400 0
*/

/*
    what is dp[i][j] ?
    dp[mask][pos] denotes the minimum cost of visiting all unvisited nodes in mask, such that the path starts from pos and ends at pos=0=A(default)
    dp[mask][0] hence denotes the final answer, which states that the starting pos=0=A, and ending pos=0=A(by default)
    Where do we set the ending pos to be constant = 0 = A by default? Well look at the base case of recursion below
*/

int tsp(int mask,int pos){

    if(mask==visitedAll)
        return cost[pos][0];            //Sab khel isi statement ka hai. This means that we are guaranteeing that starting vertex is A, and after path completion, we go back to A

    if(dp[mask][pos]!=MAX)
        return dp[mask][pos];

    for(int i=0;i<n;i++)
        if(!(mask&(1<<i)))
            dp[mask][pos]=min(dp[mask][pos],tsp(mask|(1<<i),i)+cost[pos][i]);



    return dp[mask][pos];
}

//https://practice.geeksforgeeks.org/problems/travelling-salesman-problem/0
void solve(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cost[i][j]=0;

    for(int i=0;i<=4096;i++){
        for(int j=0;j<n;j++)
            dp[i][j]=MAX;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }
    visitedAll=(1<<n)-1;

    //cost[i][j] means cost of going to 'j' from 'i'
    cout<<tsp(1,0)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

/*
1
5
0 100 2 1000 500
100 0 200 1 1000
1 200 0 300 1000
1000 1 300 0 400
500 1000 1000 400 0
*/

/*
1
5
0 100 1 1000 500
100 0 200 1 1000
1 200 0 300 1000
1000 1 300 0 400
500 1000 1000 400 0
*/

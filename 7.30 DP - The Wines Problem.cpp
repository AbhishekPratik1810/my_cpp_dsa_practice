//https://www.spoj.com/problems/TRT/
//DP always gives globally optimum solution, Greedy always gives locally optimum solution. If using greedy(here selecting a bottle) has an impact on other remaining elements(bottles) => Don't use greedy
#include<iostream>
#include<algorithm>

using namespace std;

int memo[2000][2000]={0};

int bruteForce(int cost[],int currYear,int beg,int end){
    if(beg==end)
        return cost[beg]*currYear;
    if(memo[beg][end]!=0) return memo[beg][end];
    return memo[beg][end] = max(bruteForce(cost,currYear+1,beg+1,end)+cost[beg]*currYear,bruteForce(cost,currYear+1,beg,end-1)+cost[end]*currYear);
}

int bottomUp(int cost[],int N){
    //Fill This diagonally;
    static int dp[2000][2000]={0};
    for(int i=0;i<N;i++) dp[i][i]=cost[i]*N;

    //Upper Triangular Matrix Traversal
    for(int diff=1;diff<N;diff++){
        for(int j=1;j<N;j++){
            int i = j-diff, currYear = N-diff;
            dp[i][j]=max(dp[i][j-1]+cost[j]*currYear,dp[i+1][j]+cost[i]*currYear);
        }
    }

    return dp[0][N-1];
}

int main(){
    int N; cin>>N;
    int* cost = new int[N];
    for(int i=0;i<N;i++) cin>>cost[i];
    cout<<bruteForce(cost,1,0,N-1)<<endl;
    cout<<bottomUp(cost,N)<<endl;
}

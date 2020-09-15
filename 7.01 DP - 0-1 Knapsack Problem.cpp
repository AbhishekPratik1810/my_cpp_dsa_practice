//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
/*
    There exists overlapping subproblems
    For example, for this
    1
    58
    41
    57 95 13 29 1 99 34 77 61 23 24 70 73 88 33 61 43 5 41 63 8 67 20 72 98 59 46 58 64 94 97 70 46 81 42 7 1 52 20 54 81 3 73 78 81 11 41 45 18 94 24 82 9 19 59 48 2 72
    83 84 85 76 13 87 2 23 33 82 79 100 88 85 91 78 83 44 4 50 11 68 90 88 73 83 46 16 7 35 76 31 40 49 65 2 18 47 55 38 75 58 86 77 96 94 82 92 10 86 54 49 65 44 77 22 81 52

    Why so? well, suppose at one point, I decide to take an item, and the capacity becomes cNew. at other point, the capacity remains c,
    but for subsequent calls, the capacity may once again come down to cNew. i.e, there are many ways to reach the same capacity, now for any of these ways,
    if the currItem value is same, BOOM we have an overlapping sub-problem

    Let weights = 1 2 3 4 5 6 7    and capacity = 8
    If we choose last '7', then choose nothing, and then come to '2', we are at [2][1]
    If we ignore '7','6', then choose '4','3', and then come to '2', we are at [2][1]

*/

#include<iostream>
using namespace std;

int dp[1000][1001];

int maxProfit(int currItem, int capacity, int* value, int* weight){

    if(currItem<0)
        return 0;

    if(dp[currItem][capacity]) {
        return dp[currItem][capacity];

    if(weight[currItem]>capacity)
        return dp[currItem][capacity] = maxProfit(currItem-1,capacity,value,weight);
    else
        return dp[currItem][capacity] = max(value[currItem] + maxProfit(currItem-1,capacity-weight[currItem],value,weight),
                    maxProfit(currItem-1,capacity,value,weight));

}


int main(){

    int testCases;
    cin>>testCases;

    while(testCases--){

        int totalItems, capacity;
        cin>>totalItems>>capacity;

        int value[totalItems], weight[totalItems];

        for(int i=0;i<totalItems;i++)
            cin>>value[i];

        for(int i=0;i<totalItems;i++)
            cin>>weight[i];

        for(int i=0;i<totalItems;i++)
            for(int j=0;j<=capacity;j++)
                dp[i][j]=0;

        cout<<maxProfit(totalItems-1,capacity,value,weight)<<endl;


    }

}

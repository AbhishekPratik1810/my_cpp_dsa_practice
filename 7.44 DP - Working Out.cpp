//https://codeforces.com/problemset/problem/429/B
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int lahub[1001][1001]={};
int lahubina[1001][1001]={};

int main() {

	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int row,col; cin>>row>>col;
    vector<vector<int>> matrix(row+1,vector<int>(col+1));

    for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++)
            cin>>matrix[i][j];

    lahub[1][1]=matrix[1][1];
    for(int i=2;i<=row;i++) lahub[i][1]=lahub[i-1][1]+matrix[i][1];
    for(int j=2;j<=col;j++) lahub[1][j]=lahub[1][j-1]+matrix[1][j];

    lahubina[row][1]=matrix[row][1];
    for(int i=row-1;i>=1;i--) lahubina[i][1]=lahubina[i+1][1]+matrix[i][1];
    for(int j=2;j<=col;j++) lahubina[row][j]=lahubina[row][j-1]+matrix[row][j];

    for(int i=2;i<=row;i++)
        for(int j=2;j<=col;j++)
            lahub[i][j]=max(lahub[i-1][j],lahub[i][j-1])+matrix[i][j];

    for(int i=row-1;i>=1;i--)
        for(int j=2;j<=col;j++)
            lahubina[i][j]=max(lahubina[i][j-1],lahubina[i+1][j])+matrix[i][j];

//    for(int i=1;i<=row;i++){
//        for(int j=1;j<=col;j++)
//            cout<<lahub[i][j]<<" ";
//        cout<<endl;
//    }
//    cout<<"---x---"<<endl;
//    for(int i=1;i<=row;i++){
//        for(int j=1;j<=col;j++)
//            cout<<lahubina[i][j]<<" ";
//        cout<<endl;
//    }

    long long ans = -1e18;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){

        }
    }


	return 0;
}

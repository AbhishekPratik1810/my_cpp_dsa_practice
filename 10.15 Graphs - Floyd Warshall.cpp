#include<iostream>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int v; cin>>v;
        int adjMat[100][100];
        for(int i=0;i<v;i++)
            for(int j=0;j<v;j++)
                cin>>adjMat[i][j];

        for(int k=0;k<v;k++)
            for(int i=0;i<v;i++)
                for(int j=0;j<v;j++)
                    adjMat[i][j]=min(adjMat[i][j],adjMat[i][k]+adjMat[k][j]);


        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(adjMat[i][j]==10000000) cout<<"INF"<<" ";
                else cout<<adjMat[i][j]<<" ";
            }
            cout<<endl;
        }


    }

}

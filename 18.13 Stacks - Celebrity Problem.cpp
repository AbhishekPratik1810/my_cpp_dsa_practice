//https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

int getId(int M[MAX][MAX], int n)
{

   stack<int> potentialCandidates;

   for(int i=0;i<n;i++)
        potentialCandidates.push(i);

   while(potentialCandidates.size()>1){
       int candidate1 = potentialCandidates.top();
       potentialCandidates.pop();
       int candidate2 = potentialCandidates.top();
       potentialCandidates.pop();
       if(M[candidate1][candidate2])
            potentialCandidates.push(candidate2);           //candidate1 knows candidate2 => candidate1 isn't celebrity
       else
            potentialCandidates.push(candidate1);           //candidate2 isn't known by someone => not celebrity
   }

   int potentialCandidate = potentialCandidates.top();

   for(int i=0;i<n;i++){
       if(i!=potentialCandidate &&  (M[potentialCandidate][i] || !M[i][potentialCandidate]))
        return -1;
   }
   return potentialCandidate;


}

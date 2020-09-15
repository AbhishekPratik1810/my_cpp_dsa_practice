//https://practice.geeksforgeeks.org/problems/ugly-numbers/0

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> ans;
vector<long long> uglyNumbers(10001,0);

bool isUgly(int curr){

    while(curr%2==0)
        curr/=2;

    while(curr%3==0)
        curr/=3;

    while(curr%5==0)
        curr/=5;

    return curr==1;
}

void bruteForce(){

    int curr=1;

    while(ans.size()<1000){
        bool ok = isUgly(curr);
        if(ok) ans.push_back(curr);
        curr++;
    }
}

void usingDP(){

    //1 based indexing
    int p2,p3,p5,idxCurr=2; p2=p3=p5=1;       //Using p2,p3,p5 we will traverse the current uglyNumbers array for each of the multiples of 2,3,5 respectively

    uglyNumbers[1]=1;

    for(int i=1;i<10000;i++){

        uglyNumbers[idxCurr] = min({uglyNumbers[p2]*2,uglyNumbers[p3]*3,uglyNumbers[p5]*5});

        if(uglyNumbers[idxCurr]==uglyNumbers[p2]*2) p2++;
        if(uglyNumbers[idxCurr]==uglyNumbers[p3]*3) p3++;               //Why Not ElseIf? To ensure that the number isn't counted duplicated in the next turn
        if(uglyNumbers[idxCurr]==uglyNumbers[p5]*5) p5++;

        idxCurr++;

    }


}


int main(){

    //bruteForce();

    usingDP();

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        //cout<<ans[n-1]<<endl;
        cout<<uglyNumbers[n]<<endl;
    }

}

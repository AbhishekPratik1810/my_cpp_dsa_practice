//https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0

#include<iostream>
#include<vector>
using namespace std;


void factorial(int n){

    vector<int> res;
    res.push_back(1);
    int cSize=1;

    for(int i=2;i<=n;i++){

        int carry=0,cDig,cPdt;

        for(int j=0;j<cSize;j++){

            cDig = res[j];
            cPdt = cDig*i + carry;
            res[j] = cPdt%10;
            carry = cPdt/10;
        }

        while(carry){
            res.push_back(carry%10);
            carry/=10;
        }
        cSize = res.size();
    }

    for(int i=cSize-1;i>=0;i--)
        cout<<res[i];
    cout<<endl;

}


int main(){

    int n; cin>>n;
    factorial(n);

}

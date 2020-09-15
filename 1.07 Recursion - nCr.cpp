#include <iostream>
using namespace std;

int computeNCR(int n, int r){
    if(r==1)
        return n;
    else{
        return computeNCR(n,r-1)*((float)(n+1-r)/r);
    }

}

int pascalTriangleNCR(int n, int r){


    if(r==0 || n==r)
        return 1;
    else
        return pascalTriangleNCR(n-1,r-1)+pascalTriangleNCR(n-1,r);
}

int main(){
    int n,r,val;
    char c;
    cin>>n>>c>>r;
    //val = computeNCR(n,r);
    val = pascalTriangleNCR(n,r);
    cout<<n<<"C"<<r<<" is "<<val;
    return 0;
}

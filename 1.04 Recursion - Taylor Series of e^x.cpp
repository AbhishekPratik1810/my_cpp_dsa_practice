#include<iostream>
using namespace std;

int pow(int b, int n){
    if(n==0)
        return 1;
    else
        return b*pow(b,n-1);
}

int fact(int n){
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}


float expUsingTaylorSeries(int x, int n){
    if(n==0)
        return 0;
    else
        return expUsingTaylorSeries(x,n-1) + (float) pow(x,n-1)/fact(n-1);
}

float expUTSviaStatic(int x, int n){
    static int p=1,f=1; //(x^n)/n! , x^n = p,  n! = f;
    if(n==1)
        return 1;
    else{
        float result= expUTSviaStatic(x,n-1);
        //To perform at returning time
        p = p*x ; f = f*(n-1);
        return result  + (float) p/f;
    }
}


int main(){
    int x,n;
    float value;
    char comma;
    cin>>x>>comma>>n;
    //value = expUsingTaylorSeries(x,n);
    value = expUTSviaStatic(x,n);
    cout<<"e^"<<x<<" for "<<n<<" terms = "<<value;

}

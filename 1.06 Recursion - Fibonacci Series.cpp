#include <iostream>
using namespace std;

void displayFibonacciSeries(int n){

    static int current = 1, prev = 0;
    if(n==2){
        cout<<0<<" "<<1<<" ";
        return;
    }else{
        displayFibonacciSeries(n-1);
        int newCurrent = current+prev;
        cout<<newCurrent<<" ";
        prev = current;
        current = newCurrent;
        return;
    }
}

void storeFibonacciSeries(int fibo[],int n){
    static int current=1,prev=0;
    if(n==1){
        fibo[0]=0;
    }else if(n==2){
        fibo[0]=0;
        fibo[1]=1;
    }else{
        storeFibonacciSeries(fibo,n-1);
        int newCurrent = current+prev;
        prev = current;
        current = newCurrent;
        fibo[n-1] = newCurrent;
    }
}

void pointerFS(int* p, int n){
    static int current=1, prev=0;
    if(n==1){
        *p=0;
    }else if(n==2){
        *p=0;
        *(p+1)=1;
    }else{
        pointerFS(p,n-1);
        int newCurrent = current + prev;
        prev=current;
        current = newCurrent;
        *(p+n-1)=current;
    }
}

int sirFS(int n){
    if(n<=2){
        return n-1;
    }else{
        int result = sirFS(n-2)+sirFS(n-1);
        return result;

    }

}

int fibFast(int* p, int n){
    if(n<=2){
        *(p+n-1)=n-1;
        return n-1;
    }
    else{
        if(*(p+n-2)== -1)
            *(p+n-2)=fibFast(p,n-1);
        if(*(p+n-3)== -1)
            *(p+n-3)=fibFast(p,n-2);
        *(p+n-1)=*(p+n-2) + *(p+n-3);
        return *(p+n-2) + *(p+n-3);
    }
}


int main(){
    int n;
    cout<<"Till what Number should fibonacci series be displayed: ";
    cin>>n;

    //displayFibonacciSeries(n);
    /*int fibo[n];
    storeFibonacciSeries(fibo,n);
    for(int i=0;i<n;i++)
        cout<<fibo[i]<<" ";*/

    int* p = new int[n];
    pointerFS(p,n);
    for(int i=0;i<n;i++)
        cout<<*(p+i)<<" ";
    cout<<"\n";

    //sirFS(n);

    for(int i=0;i<n;i++)
        *(p+i)=-1;

    fibFast(p,n);
    for(int i=0;i<n;i++)
        cout<<*(p+i)<<" ";

    return 0;
}


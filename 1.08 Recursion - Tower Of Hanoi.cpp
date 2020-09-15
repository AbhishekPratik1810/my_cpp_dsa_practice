//1. Shift from A to B using C Magically(Recursively)
//2. Move Last bar from A to C
//3. Shift from B to C using A Magically(Recursively)

#include<iostream>

using namespace std;

int steps;

void towerOfHanoi(int beg,int end, int from, int to, int withHelpOf){

    if(beg>end)
        return;

    towerOfHanoi(beg+1,end,from,withHelpOf,to);
    steps++;
    cout<<"move disk "<<beg<<"from rod "<<from<<" to rod "<<to<<endl;
    towerOfHanoi(beg+1,end,withHelpOf,to,from);

}


int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        steps=0;
        towerOfHanoi(1,n,1,3,2);
        cout<<steps<<endl;
    }


}





/*
#include <iostream>
#include <string>
using namespace std;

struct Tower{
    int* bars;
    char name;
};
void TOH(int n, struct Tower source, struct Tower usingTow, struct Tower destination){
        static int j=n;
        if(n==1){
            cout<<"Move "<<source.bars[j-1]<<" From "<<source.name<<" To "<<destination.name<<" Using "<<usingTow.name<<endl;
            destination.bars[j-1]=source.bars[j-1];    //Not desitnation.bars[0]
            source.bars[j-1]=-1;
        }else{
            TOH(n-1,source,destination,usingTow);
            cout<<"Move "<<source.bars[j-n]<<" From "<<source.name<<" To "<<destination.name<<" Using "<<usingTow.name<<endl;
            destination.bars[j-n]=source.bars[j-n];    ////Not desitnation.bars[0]
            source.bars[j-n]=-1;
            TOH(n-1,usingTow,source,destination);
        }

}



int main(){
    int n;
    cin>>n;

    struct Tower A,B,C;
    A.bars = new int[n]; A.name='A';
    B.bars = new int[n]; B.name='B';
    C.bars = new int[n]; C.name='C';


    for(int i=n,j=0;i>0;i--,j++)
        A.bars[j]=i;

    TOH(n,A,B,C);

    cout<<"------------------"<<"\n";
    for(int i=0;i<n;i++){
        //cout<<A[i]<<"\t"<<B[i]<<"\n";
        cout<<A.bars[i]<<"\t"<<C.bars[i]<<"\n";
    }
    cout<<"------------------"<<"\n";


    return 0;
}
*/

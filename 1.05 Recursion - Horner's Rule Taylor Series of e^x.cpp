//Beauty of the Method? Accurately Predicts answer till any order accuracy. With factorials, accuracy is limited to 16-17 terms(i.e value of n, try (x,n) = (3,20) in previous
//examples for instance. Here, since it is normal multiplication, n can be anything

#include <iostream>
using namespace std;


float hornerRuleTS(int x, int n){
    static int counter = 0;
    if(n==1)
        return 1;
    else{
        counter++;
        float result = 1+((float)x/counter)*hornerRuleTS(x,n-1);
        counter--;
        return result;
    }
}

float sirHRTS(int x, int n){
    //Everything is to be performed at calling time
    static float result = 1;
    if(n==1)
        return result;
    else
        result = 1 +(x*result/(n-1)) ;                    //Instead of type casting to float, multiplied by float so that the numerator is float and float/int = float

    return sirHRTS(x,n-1);
}

float iterativeTS(int x,int n){
    float sum = 1;
    for(;n>1;n--)
        sum = 1 + (x*sum)/(n-1);
    return sum;
}

int main(){
    int x,n;
    char c;
    cin>>x>>c>>n;
    //float value = hornerRuleTS(x,n);
    //float value = sirHRTS(x,n);
    float value = iterativeTS(x,n);
    cout<<"e^"<<x<<" for "<<n<<" terms = "<<value;

}

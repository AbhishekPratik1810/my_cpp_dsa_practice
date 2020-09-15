#include<iostream>
using namespace std;

//WCT : O(n)
void findDuplicates(string s){
    //Assuming a string with only either only small/capital letters will have 26 character options. => we can choose nearest byte(here 32 bits = 4byte = sizeOf(int)
    int bitset=0;  //To Shift x, also note, now bitset is assumed to have index 0 for LSB, not MSB

    for(int i=0;s[i]!='\0';i++){
        int x=1;
        x<<=s[i]-97;                    //Assume if all lower letters, then 'a' corresponds to 0 and 'z' corresponds to 25. 'a' actually corresponds to 97
        if((x & bitset) !=0)
            cout<<"Duplicate "<<s[i]<<" found at "<<i<<endl;
        else
            bitset = bitset | x;
    }
}

int main(){
    string s;
    cin>>s;
    findDuplicates(s);
}

//https://codeforces.com/contest/514/problem/A
#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int l = s.size();
    for(int i=0;i<l;i++){
        //cout<<i<<endl;
        if(i==0 && s[0]=='0'){
            while(i<l && s[i]=='0')
                s[i++]='9';
            i--;
        }else if(i==0 && s[0]=='9'){
            continue;
        }
        else if(s[i]-'0'>'4'-'0')
            s[i]=(9-(s[i]-'0'))+'0';
    }
    cout<<s<<endl;

}


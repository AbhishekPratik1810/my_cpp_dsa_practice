#include<bits/stdc++.h>
using namespace std;

map<int,char> letters;

int getNumber(string s){
    return stoi(s);
}

vector<string> possibleStrings(int currPos, string &s){

    if(currPos==s.size())
        return vector<string> (1,"");

    vector<string> res;


    for(int i=currPos;i!=s.size();i++){

        int currNum = getNumber(s.substr(currPos,i-currPos+1));         //i-currPos+1 denotes the length of currString
        if(currNum<=26){
            vector<string> fwd = possibleStrings(i+1,s);                //i+1 denotes the index from where the next recursive call starts = currPos + length of currString = i+1
            for(auto str : fwd)
                res.push_back(letters[currNum]+str);

        }else
            break;
    }

    return res;

}

int main(){


    for(int i=1;i<=26;i++)
        letters[i] = (char) 'A'+i-1;

    string s;
    cin>>s;

    vector<string> res = possibleStrings(0,s);

    for(auto str : res)
        cout<<str<<endl;

}

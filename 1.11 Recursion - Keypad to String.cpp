//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include<bits/stdc++.h>
using namespace std;

map<int,string> letters;


vector<string> getCombination(int currIdx, string &s){

    if(currIdx==s.size())
        return vector<string> (1,"");

    vector<string> fwd = getCombination(currIdx+1,s);
    vector<string> ans;

    for(auto ch : letters[s[currIdx]-'0']){
        for(auto str : fwd)
            ans.push_back(ch+str);
    }
    return ans;

}


void letterCombinations(string &s) {

    vector<string> res;

    res = getCombination(0,s);

    for(auto str: res)
        cout<<str<<" ";

    cout<<endl;

}

int main(){


    letters[2]="abc";
    letters[3]="def";
    letters[4]="ghi";
    letters[5]="jkl";
    letters[6]="mno";
    letters[7]="pqrs";
    letters[8]="tuv";
    letters[9]="wxyz";

    string s;
    cin>>s;

    letterCombinations(s);

}


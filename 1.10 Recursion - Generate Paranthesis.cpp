#include<iostream>
#include<vector>

using namespace std;

void help(string curr,int openCount, int closeCount,int totalLength,vector<string> &res){

    if(openCount+closeCount==totalLength){
        res.push_back(curr);
        return;
    }

    if(openCount<(totalLength/2))
        help(curr+"(",openCount+1,closeCount,totalLength,res);

    if(closeCount<openCount)
        help(curr+")",openCount,closeCount+1,totalLength,res);

}



vector<string> generateParenthesis(int n) {

    vector<string> res;
    help("",0,0,2*n,res);
    return res;

}

int main(){

    int n ;
    cin>>n;

    vector<string> ans =  generateParenthesis(n);


    for(auto str : ans)
        cout<<str<<endl;

}

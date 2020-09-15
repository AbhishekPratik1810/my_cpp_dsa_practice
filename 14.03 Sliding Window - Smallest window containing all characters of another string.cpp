//https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string/0
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

bool possible(vector<int> &patFreq, vector<int> &strFreq){
    for(int i=0;i<26;i++){
        if(patFreq[i]>strFreq[i])
            return false;
    }
    return true;
}

int main() {

	int t; cin>>t;

	while(t--){

	    string str, pattern;
	    cin>>str>>pattern;

	    int len1 = str.size(), len2 = pattern.size();

	    int ans=INT_MAX;

	    vector<int> patFreq(26,0), strFreq(26,0);

	    for(auto c : pattern)
	        patFreq[c-'a']++;

        int windowLeft=0;
        string smallest;
        for(int windowRight=0;windowRight<len1;windowRight++){

            strFreq[str[windowRight]-'a']++;

            while(possible(patFreq,strFreq)){
                if(windowRight-windowLeft+1<ans){
                    //cout<<windowRight<<" "<<windowLeft<<endl;
                    ans = windowRight-windowLeft+1;
                    smallest = str.substr(windowLeft,ans);
                }
                strFreq[str[windowLeft++]-'a']--;
            }

        }
	    cout<<(ans==INT_MAX?"-1":smallest)<<endl;

	}
	return 0;
}

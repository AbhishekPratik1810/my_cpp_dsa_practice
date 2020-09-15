#include <bits/stdc++.h>
using namespace std;

vector<string> getPermutations(int currPos,string &s){

    if(currPos==s.size()-1){
        string a;
        a.push_back(s[currPos]);
        return vector<string> (1,a);
    }

    vector<string> fwd = getPermutations(currPos+1, s);
    vector<string> ans;

    for(auto str : fwd){

        ans.push_back(s[currPos]+str);

        int length = str.size();
        for(int i=1;i<length;i++)
            ans.push_back(str.substr(0,i) + s[currPos] + str.substr(i));


        ans.push_back(str+s[currPos]);

    }


    return ans;


}


int main() {

	int t; cin>>t;
	while(t--){

	    string s;
	    cin>>s;

	    vector<string> res = getPermutations(0,s);

	    sort(res.begin(),res.end());

	    for(auto str : res)
	        cout<<str<<" ";
	    cout<<endl;


	}
	return 0;
}

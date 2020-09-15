//https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring/0
#include <iostream>
using namespace std;

int main() {
	int t; cin>>t;

	while(t--){

	    string s; cin>>s;

	    int maxLength = 0, windowLeft = 0;
	    int pos[26];
	    for(int i=0;i<26;i++)
	        pos[i]=-1;

	    for(int windowRight=0; windowRight!=s.size(); windowRight++){

	        if(pos[s[windowRight]-'a']!=-1 && pos[s[windowRight]-'a']>=windowLeft)      //=>The duplicate character is indeed inside window
	            windowLeft = pos[s[windowRight]-'a'] + 1;

	        pos[s[windowRight]-'a'] = windowRight;

	        maxLength = max(maxLength, windowRight-windowLeft +1);

	    }

	    cout<<maxLength<<endl;


	}


	return 0;
}

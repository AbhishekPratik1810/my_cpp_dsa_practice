/*
Sanket has a string consisting of only 'a' and 'b' as the characters. Sanket describes perfectness of a string as the maximum length substring of equal characters.
Sanket is given a number k which denotes the maximum number of characters he can change. Find the maximum perfectness he can generate by changing no more than k characters.

2 ≤ N ≤ 10^6

Sample Input
2
abba

Output
4
*/

#include<iostream>
using namespace std;
int main() {
	int k; cin>>k;
	string s; cin>>s;
	int l = s.size();
	int windowLeft =0;
	int count=0,b=0,a=0;

	for(int windowRight = 0;windowRight<l;windowRight++){
		if(s[windowRight]=='b') b++;

		while(b>k){
			if(s[windowLeft]=='b') b--;
			windowLeft++;
		}

		count = max(count,windowRight-windowLeft+1);

	}

	windowLeft=0;
	for(int windowRight = 0;windowRight<l;windowRight++){
		if(s[windowRight]=='a') a++;

		while(a>k){
			if(s[windowLeft]=='a') a--;
			windowLeft++;
		}

		count = max(count,windowRight-windowLeft+1);

	}

	cout<<count<<endl;

	return 0;
}

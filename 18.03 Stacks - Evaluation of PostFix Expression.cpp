//https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression/0/
/*
    Note, first the 2nd operand is obtained, then the 1st operand, we obtain b first, then a, not vice-versa
*/
#include <iostream>
#include<stack>
using namespace std;

bool isOperand(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return 0;
    else
        return 1;
}

int operate(int a, int b, char c){
    if(c=='+')
        return a+b;
    if(c=='-')
        return a-b;
    if(c=='*')
        return a*b;
    if(c=='/')
        return a/b;
}

int main() {
	int t; cin>>t;
	while(t--){
	    stack<int> st;

	    string s; cin>>s;
	    int res;
	    for(auto c: s){
	        if(isOperand(c))
	            st.push(c-'0');
	        else{
	            int b = st.top();
	            st.pop();
	            int a = st.top();
	            st.pop();
	            res = operate(a,b,c);
	            st.push(res);
	        }
	    }

	    cout<<st.top()<<endl;

	}

	return 0;
}

//https://practice.geeksforgeeks.org/problems/infix-to-postfix/0

/*
    Point 1:
            We always ensure that any element on top will have greater precedence than those on bottom
    Point 2:
            We return -1 for precedence of '(' and handle insertion of '(' separately
*/

#include <iostream>
#include <stack>
using namespace std;

int getPrecedence(char ch){
    if(ch=='+' || ch=='-')
        return 1;
    if(ch=='*' || ch=='/')
        return 2;
    if(ch=='^')
        return 3;
    return -1;                          //for '(', we want it to stay in stack if it is present, when we are pushing an operator. To handle this, we separately deal with the pushing of '('
}
bool isOperand(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch =='(' || ch==')')
        return 0;
    else
        return 1;
}

int main() {
	int t;
	cin>>t;

	while(t--){
	    string s; cin>>s;
	    stack<char> st;

	    for(auto c:s){
	        if(isOperand(c))
	            cout<<c;
	        else{

	            if(c=='(')
	                st.push('(');
	            else if(c==')'){
	                while(!st.empty()){
	                    if(st.top()!='('){
	                        cout<<st.top();
	                        st.pop();
	                    }else{
	                        st.pop();
	                        break;
	                    }
	                }
	            }else{

	                while(!st.empty()&& getPrecedence(c)<=getPrecedence(st.top())){
	                    cout<<st.top();
	                    st.pop();
	                }

	                st.push(c);

	            }

	        }
	    }
	    while(!st.empty()){
	        cout<<st.top();
	        st.pop();
	    }
	    cout<<endl;
	}

	return 0;
}

//https://practice.geeksforgeeks.org/problems/parenthesis-checker/0

#include <iostream>
#include    <stack>
using namespace std;

int main() {


	int t;
	cin>>t;
	while(t--){
        stack<char> st;
        string s;
        cin>>s;
        bool ok=1;
        for(auto c:s){
            if(c=='(' || c=='{' || c=='[')
                st.push(c);
            else if(c==')'){
                if(st.empty()||st.top()!='('){
                    ok=0; break;
                }else
                    st.pop();
            }else if(c=='}'){
                if(st.empty()||st.top()!='{'){
                    ok=0; break;
                }else
                    st.pop();
            }else{
                if(st.empty()||st.top()!='['){
                    ok=0; break;
                }else
                    st.pop();
            }
        }

        if(ok && st.empty())
            cout<<"balanced"<<endl;
        else
            cout<<"not balanced"<<endl;


	}

	return 0;
}

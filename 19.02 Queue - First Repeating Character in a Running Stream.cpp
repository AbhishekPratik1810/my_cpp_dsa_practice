//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0
#include <iostream>
#include<queue>
using namespace std;


void moreSubtle(vector<char> &s){

    int freq[26]={};
    queue<char> q;

    for(auto c:s){

        freq[c-'a']++;
        q.push(c);

        while(!q.empty() && freq[q.front()-'a']>1)
            q.pop();

        if(q.empty())
            cout<<-1<<" ";
        else
            cout<<q.front()<<" ";

    }


}


int main() {

    int t; cin>>t;

    while(t--){


        int n; cin>>n;
        vector<char> s(n);
        for(int i=0;i<n;i++)
            cin>>s[i];

        int freq[26]={};
        queue<char> q;

        for(auto c:s){

            if(freq[c-'a']==0)
                q.push(c);
            else{

                if(!q.empty() && q.front()==c)
                    q.pop();

                //Remove those who may have been repeated in between
                while(!q.empty() && freq[q.front()-'a']>1)
                    q.pop();
            }

            if(q.empty())
                cout<<-1<<" ";
            else
                cout<<q.front()<<" ";

            freq[c-'a']++;

        }

        cout<<endl;


    }

	return 0;
}

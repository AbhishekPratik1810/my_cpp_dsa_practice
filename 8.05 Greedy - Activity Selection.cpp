//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int> start(n);
        vector<int> finish(n);

        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>finish[i];

        vector<pair<int,int>> activities(n);

        for(int i=0;i<n;i++)
            activities[i]=make_pair(start[i],finish[i]);

        sort(activities.begin(),activities.end(),compare);

        vector<pair<int,int>> res;

        int currSecond=INT_MIN;

        for(int i=0;i<n;i++){
            if(activities[i].first>=currSecond){
                currSecond=activities[i].second;
                res.push_back(make_pair(activities[i].first,activities[i].second));
            }
        }

        for(auto p: res)
            for(int i=0;i<n;i++)
                if(p.first==start[i] && p.second ==finish[i])
                    cout<<i+1<<" ";

        cout<<endl;


    }

}

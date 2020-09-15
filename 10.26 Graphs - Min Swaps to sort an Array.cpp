//https://practice.geeksforgeeks.org/problems/minimum-swaps/1
//https://www.hackerrank.com/challenges/minimum-swaps-2/problem

#include<bits/stdc++.h>

using namespace std;

int usingGreedy(vector<int> &arr, int n){

        int* temp = new int[n];

        vector<int> mp(1000001);        //map gives TLE as all operations are O(logn) whereas they are O(1) for a vector

        for(int i=0;i<n;i++){
            temp[i]=arr[i];
            mp[arr[i]] = i;

        }

        int count=0;

        sort(temp,temp+n);

        for(int i=0;i<n;i++){
            if(arr[i]!=temp[i]){

                int curr = arr[i], toSwapWith = temp[i];
                int idxCurr = i, idxTSW = mp[toSwapWith];

                swap(arr[i],arr[idxTSW]);

                mp[toSwapWith] = idxCurr;
                mp[curr] = idxTSW;

                ++count;
            }
        }

        return count;
}

int cTime=0;

bool ancestor[1000001], vis[1000001];
int discoveryTime[1000001];

void dfs(int src,int &count,map<int,vector<int>> &adjList){

    vis[src]=ancestor[src]=1;
    discoveryTime[src]=cTime++;
    for(auto i : adjList[src]){
        if(!vis[i])
            dfs(i,count,adjList);
        else if(ancestor[i])
            count+=discoveryTime[src]-discoveryTime[i];
    }
    ancestor[src]=0;
}

int usingGraphs(vector<int> &arr, int n){

    map<int,vector<int>> adjList;
    int* temp = new int[n];

    vector<int> indices(1000001);

    for(int i=1;i<=n;i++) {
            temp[i-1]=arr[i-1];
            indices[arr[i-1]]=i;
    }

    sort(temp,temp+n);

    vector<int> outOfPlace;

    for(int i=1;i<=n;i++){
        if(temp[i-1]!=arr[i-1]){
            adjList[indices[temp[i-1]]].push_back(i);               //getting all incoming edges
            outOfPlace.push_back(i);
        }
    }

    cTime=0;

    for(auto i : outOfPlace) {
            vis[i]=ancestor[i]=0;
            discoveryTime[i]=0;
    }

    int count=0;

    for(auto i : outOfPlace){
        if(!vis[i])
            dfs(i,count,adjList);
    }


    return count;

}

int main()
{

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        vector<int> arr(n);

        for(int i=0;i<n;i++)
            cin>>arr[i];

        //cout<<usingGreedy(arr,n)<<endl;
        cout<<usingGraphs(arr,n)<<endl;

    }

}

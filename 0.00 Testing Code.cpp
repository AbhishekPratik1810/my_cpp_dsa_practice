#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);


    int t; cin>>t;

    while(t--){

        string inp; cin>>inp;

        vector<int> arr(9);

        for(int i=0;i<=8;i++)
            arr[i]=i+1;

        for(int i=0;i<8;i++){
            if((inp[i]-'0')%2==0)
                inp[i]='1';
            else
                inp[i]='0';

        }
        string ans = "not";

        int count=0;

        do{

            string val = "";

            for(int i=0;i<=8;i++)
                val+= (arr[i]+'0');

            bool ok = 1;

            for(int i=0;i<8;i++){
                if(inp[i]=='1'){
                    if(val[i]>=val[i+1]){
                        ok = 0;
                        break;
                    }
                }else{
                    if(val[i]<=val[i+1]){
                        ok = 0;
                        break;
                    }
                }
            }

            if(ok){
                if(ans=="not")
                    ans = val;
                else{
                    //int v1 = stoi(ans);
                    //int v2 = stoi(val);
                        ans = val;

                }
            }

        }while(next_permutation(arr.begin(),arr.end()));



        cout<<ans<<"\n";
    }


}





/*
10
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
*/

/*
100
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
25426251
*/
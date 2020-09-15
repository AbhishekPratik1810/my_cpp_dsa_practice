//https://leetcode.com/problems/longest-consecutive-sequence/

//O(N)
int longestConsecutive(vector<int>& arr) {

        int n = arr.size();
        int longestStreak = 0, currStreak,currNum;

        unordered_map<int,bool> isPresent;

        for(auto i : arr)
            isPresent[i] = 1;

        for(auto num : arr){
            currStreak = 1;
            currNum = num;
            isPresent[num]=0;
            while(isPresent[currNum+1]){
                currStreak++;
                currNum++;
                isPresent[currNum]=0;
            }

            currNum = num;
            while(isPresent[currNum-1]){
                currStreak++;
                currNum--;
                isPresent[currNum]=0;
            }

            longestStreak = max(longestStreak,currStreak);

        }

        return longestStreak;

}

//O(NLogN)
int longestConsecutive(int arr[]){

        sort(arr,arr+n);

	    int ans=0,curr=1;

        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]) continue;
            if(arr[i]-arr[i-1]==1)
                curr++;
            else{
                ans=max(ans,curr);
                curr=1;
            }
        }
        ans=max(ans,curr);

	    return ans;
}

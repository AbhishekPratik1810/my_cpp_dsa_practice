//https://www.geeksforgeeks.org/count-subarrays-with-sum-equal-to-its-xor-value/

#include<iostream>

using namespace std;

int optimizedSlidingWindow(int arr[], int n){

    int windowStart, windowEnd=0, currSum=0, largestPossibleIndex = n-1, answer = 0;

    for(windowStart=0; windowStart<=largestPossibleIndex;windowStart++){

        while(windowEnd<=largestPossibleIndex && currSum+arr[windowEnd] == (currSum^arr[windowEnd]))
            currSum += arr[windowEnd++];

        answer += windowEnd-windowStart;    //Gives count of all those subarrays which start at windowStart

        if(windowStart==windowEnd)
            windowEnd++;            //We are slowly approaching right from left after the largest window starting at windowStart was obtained. Once approached, increment windowRight

        currSum -= arr[windowStart];       //You have been counted for!

    }

    return answer;
}

int main(){

    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int windowStart, windowEnd, currSum=0, largestPossibleIndex = n-1, answer=0;


    //O(n^2) Consider 0 0 0 0... Now note this is because when we are doing windowEnd = windowStart, we are allowing the possibility to make the window traverse the array again
    //Can we do better? Can we make windowEnd stay where it was and then conclude about the answer for the upcoming element? Yes
    //2,5,16 In first pass, windowEnd = 3, now don't make windowEnd = windowStart again. Instead use the fact that for windowStart = 1, answer will still be windowEnd-windowStart
    for(windowStart=0;windowStart<=largestPossibleIndex;windowStart++){

        windowEnd = windowStart;
        currSum = 0;

        while(windowEnd<=largestPossibleIndex && currSum+arr[windowEnd] == (currSum ^ arr[windowEnd])){
            currSum += arr[windowEnd];
            windowEnd++;
        }


        answer += windowEnd-windowStart;

    }

    cout<<answer<<endl;

    cout<<optimizedSlidingWindow(arr,n)<<endl;

}


/*
Now, agar ye question me hume ye pata chal jaye ki
i) What is the count of all those subarrays which have sum equal to xor such that the subarray starts at '2'
ii) .... .... starts at '5'
iii) ... .... starts at '16'

Then answer will be i + ii + iii

Now let us solve case i)

Ek window lenge, jiska starting point is '2', ye kaise milega? well index of 2 is 0, so lets start a window with index 0
Let me call it windowStart = 0
Also, is window me jo bhi sum aayega, usko main ek variable se denote karunga, called currSum. It will be initialized to 0 initially

Ab, ek windowEnd lenge, jiska starting position will be windowStart (i.e here it will be 0)
windowEnd ko basically ab increase karte rahenge such that we find the "longest subarray" which satisfies the property

uska code kuch aisa dikhega

while(windowEnd<=lastPossibleIndex && currSum+arr[windowEnd] == currSum^arr[windowEnd])  	//lastPossibleIndex = length of array-1, here 2
     currSum += arr[windowEnd];
     windowEnd++;
}

There are 2 major observations

1) The while loop will run at least once. This is because, every singleton satifies this property.
2) The total length of window will give me the answer

Let me denote length of longest subarray with the property as longestWithProperty

longestWithProperty = windowEnd - windowStart
(This is because, as the while loop runs at least once, windowEnd > windowStart )

The 2nd observation seems tricky. Ye kaise answer dega? Humne toh "longest subarray" ka length find kiya hai.
Well here is the explanation.

For Case 1, we have found out the longest Subarray as {2,5,16}, the length being 3, with windowStart=0, windowEnd=3 (Loop stopped as windowRight>lastPossibleIndex=2)
Now, there are 3 subarrays satisfying condition i), namely {2}, {2,5}, {2,5,16}
Hence the length of the longest subarray will always give me the answer

Now to solve for case ii) and iii) we can simply iterate windowStart from firstIndex till lastIndex
*/

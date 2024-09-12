#include<bits/stdc++.h>
using namespace std;

// HASH - PREFIX SUM
// FOR POSITIVE, NEGATIVE AND ZEROES
class HashPrefixSum{
    public:
    int lenOfLongestSubarrayWithSumK(vector<int> &nums, int k) { 
        int n = nums.size();
        long long sum = 0, ans = 0;

        unordered_map<long long, int> mp;
        
        for(long long i=0; i<n; ++i){
            //Step 1 : find the prefix
            sum += nums[i];
            
            //Step 2 : check if this prefix equals K
            if(sum == k) ans =  i+1;
            
            //Step 3 : Check if the complement exists in map
            if(mp.find(sum - k) != mp.end()) ans = max(ans, i - mp[sum-k]);
            
            //Step 4 : Insert only if the sum already doesnt exist
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return ans;
    } 
};

// SLIDING WINDOW
// ZEROES INCLUDED
class SlidingWindow{

};

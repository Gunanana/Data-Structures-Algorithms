#include<bits/stdc++.h>
using namespace std;

#define ll long long

class HashPrefixSum{
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<ll,ll> mp;
        int n = nums.size();
        ll sum = 0, ans = 0;

        for(int i=0; i<n; ++i){
            // Step 1 : Get prefix
            sum += nums[i];

            // Step 2 : Check if prefix equals goal
            if(sum == k) ans++;

            // Step 3 : Check if complement exists, if yes += its frequency
            int comp = sum - k;
            if(mp.find(comp) != mp.end()) ans += mp[comp];

            // Step 4 : Increase the fq of current prefix sum
            mp[sum]++;
        }

        return ans;
    }
};
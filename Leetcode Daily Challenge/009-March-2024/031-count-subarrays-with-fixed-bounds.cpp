// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans  = 0;
        int minIdx     = -1;
        int maxIdx     = -1;
        int culpritIdx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) 
                culpritIdx = i;

            if (nums[i] == minK) minIdx = i;
            if (nums[i] == maxK) maxIdx = i;
            
            ans += max(0, min(minIdx, maxIdx) - culpritIdx);
        }
        return ans;
    }
};
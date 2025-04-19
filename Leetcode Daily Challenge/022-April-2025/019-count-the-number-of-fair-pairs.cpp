// https://leetcode.com/problems/count-the-number-of-fair-pairs/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N * log(N))
    // SC : O(1)
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        long long cntPairs = 0;
        for (int i = 0; i < n; i ++) {
            // Gives the first index which is NOT LESS than (lower - nums[i])
            int lower_idx = lower_bound(begin(nums) + i + 1, end(nums), lower - nums[i]) - begin(nums);

            // Gives the first index which is GREATER than (upper - nums[i])
            int upper_idx = upper_bound(begin(nums) + i + 1, end(nums), upper - nums[i]) - begin(nums);

            cntPairs += (upper_idx - lower_idx);
        }

        return cntPairs;
    }
};
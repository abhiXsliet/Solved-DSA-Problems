// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0], minSum = nums[0];
        int currMaxSum = nums[0], currMinSum = nums[0];

        for (int i = 1; i < n; i ++) {
            currMaxSum = max(nums[i], currMaxSum + nums[i]);
            maxSum     = max(maxSum, currMaxSum);

            currMinSum = min(nums[i], currMinSum + nums[i]);
            minSum     = min(minSum, currMinSum);
        }

        return max(maxSum, abs(minSum));
    }
};
// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * maxOr)
    // SC : O(N * maxOr)
    int solve(int idx, vector<int>& nums, int sum, int maxOr, vector<vector<int>>& dp) {
        if (idx >= nums.size()) {
            if (sum == maxOr) 
                return 1;
            return 0;
        }

        if (dp[idx][sum] != -1) return dp[idx][sum];

        int take    = solve(idx + 1, nums, sum | nums[idx], maxOr, dp);        
        int notTake = solve(idx + 1, nums, sum, maxOr, dp);

        return dp[idx][sum] = (take + notTake);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int &num : nums) {
            maxOr |= num;
        }

        int sum = 0;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(maxOr + 1, -1));
        return solve(0, nums, sum, maxOr, dp);
    }
};
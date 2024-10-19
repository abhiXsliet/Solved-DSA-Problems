// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(2^n)
    // SC : O(n) recursive stack space
    void solve(int idx, vector<int>& nums, int &result, int sum, int &maxOr) {
        if (idx >= nums.size()) {
            if (sum == maxOr) result += 1;
            return;
        }

        solve(idx + 1, nums, result, sum | nums[idx], maxOr);        
        solve(idx + 1, nums, result, sum, maxOr);
    }

    // TC : O(n * maxOr)
    // SC : O(n * maxOr)
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

    // TC : O(2^n)
    // SC : O(1)
    int brute(vector<int>& nums) {
        int maxOr = 0;
        for (int &num : nums) {
            maxOr |= num;
        }

        int result = 0;
        int sum = 0;
        solve(0, nums, result, sum, maxOr);

        return result;
    }

    // TC : O(n * maxOr)
    // SC : O(n * maxOr)
    int optimal(vector<int>& nums) {
        int maxOr = 0;
        for (int &num : nums) {
            maxOr |= num;
        }

        int sum = 0;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(maxOr + 1, -1));
        return solve(0, nums, sum, maxOr, dp);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        return brute(nums);
        
        return optimal(nums);
    }
};
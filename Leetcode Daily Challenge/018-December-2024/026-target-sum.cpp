// https://leetcode.com/problems/target-sum/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int total;
    
    // TC : O(N * Sum)
    // SC : O(N * Sum)
    int mem(vector<int>& nums, int tar, int i, int sum, vector<vector<int>>& dp) {
        if (i >= nums.size()) {
            return sum == tar ? 1 : 0;
        }
        if (dp[i][sum + total] != -1)
            return dp[i][sum + total];

        int plus  = mem(nums, tar, i + 1, sum + nums[i], dp);
        int minus = mem(nums, tar, i + 1, sum - nums[i], dp);

        return dp[i][sum + total] = plus + minus;
    }

    // TC : O(2^N)
    // SC : O(N) Recursive Stack Space
    void solve(vector<int>& nums, int tar, int i, int sum, int &ans) {
        if (i >= nums.size()) {
            if (sum == tar) {
                ans += 1;
            }
            return;
        }
        
        solve(nums, tar, i + 1, sum + nums[i], ans);
        solve(nums, tar, i + 1, sum - nums[i], ans);
    }

    int approach_1(vector<int>& nums, int target) {
        int ans = 0;
        solve(nums, target, 0, 0, ans);
        return ans;
    }

    int approach_2(vector<int>& nums, int target) {
        int n = nums.size();
        total = accumulate(begin(nums), end(nums), 0);
        vector<vector<int>> dp(n + 1, vector<int>(2 * total + 1, -1));
        return mem(nums, target, 0, 0, dp);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // return approach_1(nums, target);    // Recursive
        
        return approach_2(nums, target);    // Recursion + Memoization
    }
};
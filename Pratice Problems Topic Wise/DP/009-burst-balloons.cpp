// https://leetcode.com/problems/burst-balloons/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(N^3)
    // SC : O(N) Recursive Stack Space
    int solve(vector<int>& nums, int i, int j, vector<vector<int>> &dp) {
        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int maxCoins = 0;
        for (int k = i; k <= j; k ++) {
            maxCoins = max(maxCoins, nums[i - 1] * nums[k] * nums[j + 1] + 
                                        solve(nums, i, k - 1, dp) + 
                                        solve(nums, k + 1, j, dp));
        }
        return dp[i][j] = maxCoins;
    }
public:
    // TC : O(N^3)
    // SC : O(N^2)
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(begin(nums), 1);
        nums.insert(end(nums), 1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(nums, 1, n, dp);
    }
};
// https://leetcode.com/problems/house-robber/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    // TC : O(2^N)
    // SC : O(N)
    int solve_rec(vector<int>& nums, int n, int idx) {
        if (idx >= n) return 0;

        int include = nums[idx] + solve_rec(nums, n, idx + 2);
        int exclude = solve_rec(nums, n, idx + 1);

        return max(include, exclude);
    }

    // TC : O(N)
    // SC : O(N)
    int solve_mem(vector<int>& nums, int n, int idx, vector<int>& dp) {
        if (idx >= n) return 0;
        
        if (dp[idx] != -1) return dp[idx];

        int include = nums[idx] + solve_mem(nums, n, idx + 2, dp);
        int exclude = solve_mem(nums, n, idx + 1, dp);

        return dp[idx] = max(include, exclude);
    }

    // TC : O(N)
    // SC : O(N)
    int solve_tab(vector<int>& nums, int n) {
        vector<int> dp(n+2, 0);
        
        for (int idx = n - 1; idx >= 0; idx--) {
            int include = nums[idx] + dp[idx + 2];
            int exclude = dp[idx + 1];

            dp[idx] = max(include, exclude);
        }
        return dp[0];
    }

    // TC : O(N)
    // SC : O(1)
    int solve_so(vector<int>& nums, int n) {
        int prev = 0;
        int curr = 0;

        for (int idx = n - 1; idx >= 0; idx--) {
            int include = nums[idx] + prev;
            int exclude = curr;

            prev = curr;
            curr = max(include, exclude);
        }
        return curr;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        // return solve_rec(nums, n, 0);

        // vector<int> dp(n+1, -1);
        // return solve_mem(nums, n, 0, dp);

        // return solve_tab(nums, n);

        return solve_so(nums, n);
    }
};
// https://leetcode.com/problems/house-robber-ii/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int solve_mem(vector<int>& nums, int n, vector<int>& dp) {
        if (n == 0) return nums[0];
        if (n < 0) return 0;

        if (dp[n] != -1) return dp[n];

        int incl = nums[n] + solve_mem(nums, n - 2, dp);
        int excl = solve_mem(nums, n-1, dp);

        return dp[n] = max(incl, excl);
    }

    // TC : O(N)
    // SC : O(N)
    int solve_tab(vector<int>& nums, int n) {
        vector<int> dp(n + 1, 0);

        dp[0] = nums[0];
        if (n > 0) dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int incl = nums[i] + dp[i - 2]; 
            int excl = dp[i - 1]; 

            dp[i] = max(incl, excl);
        }

        return dp[n - 1];
    }

    // TC : O(N)
    // SC : O(1)
    int solve_so(vector<int>& nums, int n) {
        int prev1 = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++) {
            int incl = prev2 + nums[i];
            int excl = prev1 + 0;

            int ans = max(incl, excl);

            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }

    // TC : O(N)
    // SC : O(N)
    int solve_memoization(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> first (begin(nums) + 1, end(nums));
        vector<int> second(begin(nums), end(nums) - 1);
        
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        return max(solve_mem(first, n - 2, dp1), solve_mem(second, n - 2, dp2));
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> first (begin(nums), end(nums) - 1);
        vector<int> second(begin(nums) + 1, end(nums));

        // return solve_memoization(nums);

        // return max(solve_tab(first, n - 1), solve_tab(second, n - 1));

        return max(solve_so(first, n - 1), solve_so(second, n - 1));
    }
};

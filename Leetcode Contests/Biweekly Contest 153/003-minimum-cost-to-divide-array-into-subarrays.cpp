// https://leetcode.com/problems/minimum-cost-to-divide-array-into-subarrays/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    int n;

    ll solveOptimized(vector<int> &nums, vector<int> &cost, vector<int> &pSum, vector<int> &cSum, int k, int i, vector<ll> &dp) {
        if (i >= n) return 0; 
        
        if (dp[i] != -1) return dp[i];

        ll ans = LLONG_MAX;
        for (int j = i; j < n; j++) {
            ll subarraySum  = pSum[j];
            ll subarrayCost = cSum[j] - ((i >= 1) ? cSum[i - 1] : 0);
            ll costTillEnd  = cSum[n - 1] - ((i >= 1) ? cSum[i - 1] : 0);

            ll val = (subarraySum * subarrayCost) + (k * costTillEnd);

            ans = min(ans, val + solveOptimized(nums, cost, pSum, cSum, k, j + 1, dp));
        }
        return dp[i] = ans;
    }

    ll solve(vector<int> &nums, vector<int> &cost, vector<int> &pSum, vector<int> &cSum, int k, int i, int cntOfSubArr, vector<vector<ll>> &dp) {
        if (i >= n) return 0; 
        
        if (dp[i][cntOfSubArr] != -1) return dp[i][cntOfSubArr];

        ll ans = LLONG_MAX;
        // Try all possible partitions starting from index i
        for (int j = i; j < n; j++) {
            // Calculate the sum and cost of the current subarray [i..j]
            ll subarraySum = pSum[j];
            ll subarrayCost = cSum[j] - (i > 0 ? cSum[i - 1] : 0);

            // Compute the cost of this subarray
            ll val = (subarraySum + (ll)(cntOfSubArr * k)) * subarrayCost;

            // Recursively solve for the remaining part of the array
            ans = min(ans, val + solve(nums, cost, pSum, cSum, k, j + 1, cntOfSubArr + 1, dp));
        }
        return dp[i][cntOfSubArr] = ans;
    }

    // TC : O(N^3)
    // SC : O(N^2)
    ll approach_1(vector<int>& nums, vector<int>& cost, int k, vector<int> &pSum, vector<int> &cSum) {
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));

        // Solve the problem starting from index 0 with subarray order 1
        return solve(nums, cost, pSum, cSum, k, 0, 1, dp);
    }

    // TC : O(N^2)
    // SC : O(N)
    ll approach_2(vector<int>& nums, vector<int>& cost, int k, vector<int> &pSum, vector<int> &cSum) {
        vector<ll> dp(n + 1, -1);

        return solveOptimized(nums, cost, pSum, cSum, k, 0, dp);
    }
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        n = nums.size();
        vector<int> pSum(n, nums[0]), cSum(n, cost[0]);
        for (int i = 1; i < n; i++) {
            pSum[i] = nums[i] + pSum[i - 1];
            cSum[i] = cost[i] + cSum[i - 1];
        }

        // return approach_1(nums, cost, k, pSum, cSum);
        return approach_2(nums, cost, k, pSum, cSum);
    }
};
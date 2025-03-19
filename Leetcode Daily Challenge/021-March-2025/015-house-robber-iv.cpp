// https://leetcode.com/problems/house-robber-iv/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // this fn. returns is it possible to steal from >= k houses by stealing a capability of at least mid?
    bool isPossible(vector<int> &nums, int k, int mid) {
        int cntHouse = 0;
        for (int i = 0; i < nums.size(); i ++) {
            // greedily stealing works since, given that it is always possible to steal at least k houses if there's a valid mid
            if (mid >= nums[i]) {
                cntHouse += 1;
                i ++;
            }
        }
        return cntHouse >= k;
    }

    int solve(vector<int> &nums, int n, int k, int i, vector<vector<int>> &dp) {
        if (k == 0) return 0;
        if (i >= n) return INT_MAX;
        if (dp[k][i] != -1) return dp[k][i];

        int op1 = max(nums[i], solve(nums, n, k - 1, i + 2, dp));
        int op2 = solve(nums, n, k, i + 1, dp);

        return dp[k][i] = min(op1, op2);
    }

    // TC : O(K * N)
    // SC : O(K * N)
    int approach_1(vector<int> &nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return solve(nums, n, k, 0, dp);
    } 

    // TC : O(N * log(max))
    // SC : O(1)
    int approach_2(vector<int> &nums, int k) {
        int n = nums.size();
        int low  = *min_element(begin(nums), end(nums));
        int high = *max_element(begin(nums), end(nums));
        int minCap = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(nums, k, mid)) {
                minCap = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return minCap;
    }   
public:
    int minCapability(vector<int>& nums, int k) {
        // return approach_1(nums, k); // BRUTE : Trying all possible ways (DP)

        return approach_2(nums, k);  // Binary Search
    }
};
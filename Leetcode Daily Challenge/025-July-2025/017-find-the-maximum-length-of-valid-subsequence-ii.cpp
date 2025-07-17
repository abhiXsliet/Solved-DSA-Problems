// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    unordered_map<string, int> mpp;

    int solve(vector<int> &nums, int k, int curr, int prev, int val) {
        if (curr >= n) return 0;

        string key = to_string(curr) + "," + to_string(prev) + "," + to_string(val);
        if (mpp.count(key)) return mpp[key];

        int take = 0;
        if (prev == -1 || (nums[curr] + nums[prev]) % k == val) {
            take = 1 + solve(nums, k, curr + 1, curr, val);
        }

        int notTake = solve(nums, k, curr + 1, prev, val);

        return mpp[key] = max(take, notTake);
    }

    // TC : O(N^2 * K)
    // SC : O(N^2 * K)
    int approach_1(vector<int> &nums, int k) {
        int ans = INT_MIN;
        for (int val = 0; val < k; val ++) {
            ans = max(ans, solve(nums, k, 0, -1, val));
        }
        return ans;
    }

    // TC : O(N^2)
    // SC : O(K*N)
    int approach_2(vector<int> &nums, int k) {
        vector<vector<int>> dp(k, vector<int>(n, 0));
        int maxLen = INT_MIN;

        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                int mod = (nums[i] + nums[j]) % k;
                dp[mod][i] = max(dp[mod][i], 1 + dp[mod][j]);
                maxLen     = max(maxLen, dp[mod][i]);
            }
        }

        return (maxLen + 1);
    }
public:
    int maximumLength(vector<int>& nums, int k) {
        n = nums.size();

        // return approach_1(nums, k);  // TLE
        return approach_2(nums, k);
    }
};
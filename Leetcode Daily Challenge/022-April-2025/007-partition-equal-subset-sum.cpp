// https://leetcode.com/problems/partition-equal-subset-sum/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;

    bool solve(vector<int> &nums, int i, int curr, int tar, vector<vector<int>> &dp) {
        if (i >= n || curr >= tar) 
            return curr == tar;

        if (dp[i][curr] != -1)
            return dp[i][curr];

        bool take = solve(nums, i + 1, curr + nums[i], tar, dp);
        bool notT = solve(nums, i + 1, curr, tar, dp);

        return dp[i][curr] = (take | notT);
    }

    // TC : O(N * target) Where target = sum of all elements / 2
    // SC : O(N * target)
    bool top_down(vector<int> &nums) {
        int tot = accumulate(begin(nums), end(nums), 0);
        if (tot % 2) return false;
        int target = tot / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1,  -1));
        return solve(nums, 0, 0, target, dp);
    }

    // TC : O(N * target) Where target = sum of all elements / 2
    // SC : O(N * target)
    bool bottom_up(vector<int> &nums) {
        int tot = accumulate(begin(nums), end(nums), 0);
        if (tot % 2) return false;
        int target = tot / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1,  0));

        for (int i = 0; i <= n; i ++) {
            dp[i][target] = 1;
        }

        for (int i = n - 1; i >= 0; i --) {
            for (int curr = target; curr >= 0; curr --) {
                bool take = curr + nums[i] <= target ? dp[i + 1][curr + nums[i]] : 0;
                bool notT = dp[i + 1][curr];
                dp[i][curr] = (take | notT);
            }
        }

        return dp[0][0];
    }

    // TC : O(N * target) Where target = sum of all elements / 2
    // SC : O(target)
    bool space_optimized(vector<int> &nums) {
        int tot = accumulate(begin(nums), end(nums), 0);
        if (tot % 2) return false;
        int target = tot / 2;
        vector<int> currRow(target + 1,  0), prevRow(target + 1, 0);

        currRow[target] = prevRow[target] = 1;

        for (int i = n - 1; i >= 0; i --) {
            for (int curr = target; curr >= 0; curr --) {
                bool take = curr + nums[i] <= target ? prevRow[curr + nums[i]] : 0;
                bool notT = prevRow[curr];
                currRow[curr] = (take | notT);
            }
            prevRow = currRow;
        }

        return prevRow[0];
    }
public:
    bool canPartition(vector<int>& nums) {
        n = nums.size();

        // return top_down(nums);     // 2D DP
        // return bottom_up(nums);
        return space_optimized(nums);
    }
};
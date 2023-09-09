// https://leetcode.com/problems/combination-sum-iv/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solveMem_approach_1(vector<int>& nums, int target, int index, vector<vector<int>>& dp) {
        // base case
        if (target == 0) return 1;
        if (index >= nums.size() || target < 0) return 0;

        if (dp[target][index] != -1) return dp[target][index];

        int take    = solveMem_approach_1(nums, target - nums[index], 0, dp);
        int notTake = solveMem_approach_1(nums, target, index+1, dp);

        return dp[target][index] = (take + notTake);
    }

    int solveMem_approach_2(vector<int>& nums, int target, int index, vector<vector<int>>& dp) {
        // base case
        if (target == 0) return 1;
        if (index >= nums.size() || target < 0) return 0;

        if (dp[target][index] != -1) return dp[target][index];

        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            int take = solveMem_approach_2(nums, target - nums[i], 0, dp);
            result += take;
        }

        return dp[target][index] = result;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(target+1, vector<int>(nums.size()+1, -1));
        // return solveMem_approach_1(nums, target, 0, dp);

        return solveMem_approach_2(nums, target, 0, dp);
    }
};
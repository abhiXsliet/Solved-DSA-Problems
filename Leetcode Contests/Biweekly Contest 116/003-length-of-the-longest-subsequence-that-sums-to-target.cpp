// https://leetcode.com/contest/biweekly-contest-116/problems/length-of-the-longest-subsequence-that-sums-to-target/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    
    int solve(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {
        if (target == 0) return 0;
        
        if (i == 0 || target < 0) return INT_MIN;
        
        if (dp[i][target] != -1) return dp[i][target];
        
        int include = solve(nums, target - nums[i-1], i-1, dp);
        
        if (include != INT_MIN) include++;
        
        int exclude = solve(nums, target, i-1, dp);
        
        return dp[i][target] = max(include, exclude);
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, -1));
        
        int result = solve(nums, target, nums.size(), dp);
        
        return result == INT_MIN ? -1 : result;
    }
};

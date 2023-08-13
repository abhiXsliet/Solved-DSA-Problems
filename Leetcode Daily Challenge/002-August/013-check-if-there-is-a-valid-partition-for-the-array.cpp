// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool solveRec(vector<int>& nums, int i) {
        int n = nums.size();
        // base case
        if (i >= n) return 1;
        
        bool result = 0;
        // Rule - 1 
        if (i+1 < n && nums[i] == nums[i+1])
            result = solveRec(nums, i+2);
        
        if (result) 
            return result;
        
        // Rule - 2
        if (i+2 < n && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) 
            result = solveRec(nums, i+3);
        
        if (result)
            return result;

        // Rule - 3
        if (i+2 < n && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1) 
            result = solveRec(nums, i+3);
        
        return result; 
    }

    bool solveMem(vector<int>& nums, int i, vector<int>& dp) {
        int n = nums.size();
        // base case
        if (i >= n) return 1;

        if (dp[i] != -1) return dp[i];
        
        bool result = 0;
        // Rule - 1 
        if (i+1 < n && nums[i] == nums[i+1])
            result |= solveMem(nums, i+2, dp);

        // Rule - 2
        if (i+2 < n && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) 
            result |= solveMem(nums, i+3, dp);

        // Rule - 3
        if (i+2 < n && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1) 
            result |= solveMem(nums, i+3, dp);
        
        return dp[i] = result; 
    }

    bool dcs(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) return 1;

        if (dp[i] != -1) return dp[i];

        // Rule - 1
        if (i+1 < nums.size() && nums[i] == nums[i+1]) {
            if( dcs(nums, i+2, dp) ) return dp[i] = 1;
            
            // Rule - 2
            if (i+2 < nums.size() && nums[i+1] == nums[i+2])
                if( dcs(nums, i+3, dp) ) return dp[i] = 1;
        }

        // Rule - 3
        if (i+2 < nums.size() && nums[i] + 1 == nums[i+1] && nums[i] + 2 == nums[i+2]) {
            if( dcs(nums, i+3, dp) ) return dp[i] = 1;
        }
        return dp[i] = false;
    }

public:
    bool validPartition(vector<int>& nums) {
        // // Recursive Solution -> TLE
        // return solveRec(nums, 0);


        // Recursion + Memoization
        vector<int> dp(nums.size()+1, -1);
        return solveMem(nums, 0, dp);


        // different code style
        vector<int> dp(nums.size()+1, -1);
        return dcs(nums, 0, dp);
    }
};
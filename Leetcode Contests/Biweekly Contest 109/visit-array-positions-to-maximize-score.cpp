// https://leetcode.com/contest/biweekly-contest-109/problems/visit-array-positions-to-maximize-score/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long solveRec(vector<int>& nums, int x, int parity, int index) {
        // base case
        if(index == nums.size()) return 0;

        // include a/c to parity is same
        long long include;
        if(nums[index] % 2 == parity) { // same parity
            include = nums[index] + solveRec(nums, x, parity, index+1); 
        } 
        else { // different parity
            include = nums[index] - x + solveRec(nums, x, !parity, index+1);
        }
        
        long long exclude = solveRec(nums, x, parity, index+1);
        
        return max(include, exclude);
    }
    
    long long solveRec_Mem(vector<int>& nums, int x, int parity, int index, vector<vector<long long>>& dp) {
        // base case
        if(index == nums.size()) return 0;
        
        if(dp[index][parity] != -1) return dp[index][parity];
        
        // include a/c to parity is same
        long long include;
        if(nums[index] % 2 == parity) { // same parity
            include = nums[index] + solveRec_Mem(nums, x, parity, index+1, dp); 
        } 
        else { // different parity
            include = nums[index] - x + solveRec_Mem(nums, x, !parity, index+1, dp);
        }
        
        long long exclude = solveRec_Mem(nums, x, parity, index+1, dp);
        
        return dp[index][parity] = max(include, exclude);
    }
    
    long long solveTab(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
        
        for(int index = n - 1; index >= 1; index--) {
            for(int parity = 0; parity <= 1; parity++) {
                long long include;
                if(nums[index] % 2 == parity) { // same parity
                    include = nums[index] + dp[index+1][parity]; 
                } 
                else { // different parity
                    include = nums[index] - x + dp[index+1][nums[index] % 2];
                }

                long long exclude = dp[index+1][parity];

                dp[index][parity] = max(include, exclude);
            }
        }
        return dp[1][nums[0] % 2];
    }
    
    long long solveSO(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> curr(2, 0);
        vector<long long> next(2, 0);
        
        for(int index = n - 1; index >= 1; index--) {
            for(int parity = 0; parity <= 1; parity++) {
                long long include;
                if(nums[index] % 2 == parity) { // same parity
                    include = nums[index] + next[parity]; 
                } 
                else { // different parity
                    include = nums[index] - x + next[nums[index] % 2];
                }

                long long exclude = next[parity];

                curr[parity] = max(include, exclude);
            }
            next = curr;
        }
        return next[nums[0] % 2];
    }
    
public:
    long long maxScore(vector<int>& nums, int x) {
        // // Recursion 
        // return nums[0] + solveRec(nums, x, nums[0] % 2, 1);
        
        
        // // Recursion + Memoization
        // vector<vector<long long>> dp(nums.size()+1, vector<long long>(2, -1));
        // return nums[0] + solveRec_Mem(nums, x, nums[0] % 2, 1, dp);
        
        
        // // Tabulation
        // return nums[0] + solveTab(nums, x);
        
        // Space-Optimization
        return nums[0] + solveSO(nums, x);
    }
};
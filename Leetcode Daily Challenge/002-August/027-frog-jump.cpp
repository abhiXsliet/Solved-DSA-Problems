// https://leetcode.com/problems/frog-jump/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N^2)
    // SC = O(N^2) where N = stones.size()
    bool solveMem(vector<int>& stones, int curr_stone_idx, int prev_jump, 
                unordered_map<int, int>& mpp, vector<vector<int>>& dp) {
        int n = stones.size();
        if(curr_stone_idx == n - 1) return true;

        if(dp[curr_stone_idx][prev_jump] != -1) 
            return dp[curr_stone_idx][prev_jump];

        bool result = false;
        for(int next_jump = prev_jump - 1; next_jump <= prev_jump + 1; next_jump++) {
            if(next_jump > 0) {
                int next_stone = stones[curr_stone_idx] + next_jump;

                if(mpp.find(next_stone) != mpp.end()) {
                    result = result || solveMem(stones, mpp[next_stone], next_jump, mpp, dp);
                }
            }
        }
        return dp[curr_stone_idx][prev_jump] = result;
    }

public:
    bool canCross(vector<int>& stones) {

        if(stones[1] != 1) return false;
    
        unordered_map<int, int> mpp;
        int n = stones.size();
        for(int i = 0; i < n; i++) {
            mpp[stones[i]] = i;
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        // Recursion + Memoization
        return solveMem(stones, mpp[0], 0, mpp, dp); // mpp[0] = 0 
    }
};
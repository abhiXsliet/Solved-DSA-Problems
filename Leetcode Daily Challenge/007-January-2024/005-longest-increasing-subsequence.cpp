// https://leetcode.com/problems/longest-increasing-subsequence/



#include <bits/stdc++.h>
using namespace std;

class Solution {

    // TC : O(2^n)
    // SC : O(n) -> Recursive Depth
    int solveRec(vector<int>& nums, int n, int curr, int prev) {
        if(curr == n)
            return 0;

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev])
            include = 1 + solveRec(nums, n, curr+1, curr);

        int exclude = 0 + solveRec(nums, n, curr+1, prev);

        return max(include, exclude);
    }

    // TC : O(n^2)
    // SC : O(n^2)
    int solveMem(vector<int>& nums, int n,int curr, int prev, vector<vector<int>>& dp) {
      
        if(curr == n)
            return 0;

        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];

        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev])
            include = 1 + solveMem(nums, n, curr+1, curr, dp);

        int exclude = 0 + solveMem(nums, n, curr+1, prev, dp);

        return dp[curr][prev+1] = max(include, exclude);
    }

    // TC : O(n^2)
    // SC : O(n^2)
    int solveTab(vector<int>& nums, int n) {

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for(int curr=n-1; curr>=0; curr--) {
            for(int prev=curr-1; prev>=-1; prev--) {
                
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev])
                    include = 1 + dp[curr+1][curr+1]; //prev=curr & +1 due to -1-index

                int exclude = 0 + dp[curr+1][prev+1];

                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    // TC : O(n^2)    
    // SC : O(n)
    int solveSO(vector<int>& nums, int n) {

        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr=n-1; curr>=0; curr--) {
            for(int prev=curr-1; prev>=-1; prev--) {
                
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev])
                    include = 1 + nextRow[curr+1]; //prev=curr & +1 due to -1-index

                int exclude = 0 + nextRow[prev+1];

                currRow[prev+1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

    // TC = O(nLog(n))
    // SC = O(n)
    int solveOptimal(vector<int>& nums, int n) {
        //base case
        if(n == 0)
            return 0;

        vector<int>ans;
        ans.push_back(nums[0]);

        for(int i=1; i<n; i++) {
            if(nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            }else {
                //finding index of next immediate greater element
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        // return solveRec(nums, n, 0, -1);

        // Memoization (TOP-DOWN)
        // vector<vector<int> > dp(n, vector<int>(n+1, -1));
        // return solveMem(nums, n, 0, -1, dp);

        // Tabulation (BOTTOM-UP)
        // return solveTab(nums, n);

        //Space-Optimization
        // return solveSO(nums, n);

        // Time-complexity => O(nlog(n))
        return solveOptimal(nums, n);

    }
};
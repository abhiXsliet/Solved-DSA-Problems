// https://leetcode.com/problems/longest-ideal-subsequence/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2) -> MLE
    // SC : O(N^2)
    int solveTab(string& nums, int n, int k) {

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for(int curr=n-1; curr>=0; curr--) {
            for(int prev=curr-1; prev>=-1; prev--) {

                int include = 0;
                if(prev == -1 || abs(nums[curr] - nums[prev]) <= k)
                    include = 1 + dp[curr+1][curr+1]; //prev=curr & +1 due to -1-index

                int exclude = 0 + dp[curr+1][prev+1];

                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    // TC : O(N^2) -> TLE
    // SC : O(N)
    int solveSO(string& nums, int n, int k) {

        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr=n-1; curr>=0; curr--) {
            for(int prev=curr-1; prev>=-1; prev--) {
                
                int include = 0;
                if(prev == -1 || abs(nums[curr] - nums[prev]) <= k)
                    include = 1 + nextRow[curr+1]; //prev=curr & +1 due to -1-index

                int exclude = 0 + nextRow[prev+1];

                currRow[prev+1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

    // TC : O(N)
    // SC : O(1)
    int solve_optimal(string& s, int n, int k) {
        vector<int> t(26, 0);
        int result = 0;
        for (int i = 0; i < n; i ++) {
            int curr  = s[i] - 'a';
            int left  = max(0, curr - k);
            int right = min(25, curr + k); 

            int longest = 0;
            for (int j = left; j <= right; j ++) {
                longest = max(longest, t[j]);
            }

            t[curr] = max(t[curr], longest + 1);
            result  = max(result, t[curr]);
        }
        return result;
    }
public:
    int longestIdealString(string s, int k) {
        // return solveTab(s, s.length(), k);
        
        // return solveSO(s, s.length(), k);

        return solve_optimal(s, s.length(), k);
    }
};
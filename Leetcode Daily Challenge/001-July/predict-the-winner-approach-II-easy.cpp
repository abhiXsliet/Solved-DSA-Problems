// https://leetcode.com/problems/predict-the-winner/



#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(2^N) exponential
    // SC = O(N) -> Recursion depth of call stack

    // finding the difference of score from player1 - player2
    int solveRecII(int i, int j, vector<int>& nums) {
        //base case
        if(i == j) return nums[i];
        if(i > j) return 0;

        //include 
        int include_front = nums[i] - solveRecII(i+1, j, nums);
        int include_back = nums[j] - solveRecII(i, j-1, nums);

        return max(include_front, include_back);
    }

    // TC = O(N^2)
    // SC = O(N^2)
    int solveRecII_Mem(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        //base case
        if(i == j) return nums[i];
        if(i > j) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        //include 
        int include_front = nums[i] - solveRecII_Mem(i+1, j, nums, dp);
        int include_back = nums[j] - solveRecII_Mem(i, j-1, nums, dp);

        return dp[i][j] = max(include_front, include_back);
    }


    // TC = O(N^2)
    // SC = O(N^2)
    int solveTabII(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp (n+1, vector<int>(n+1, 0));

        // Analysizing base case
        for(int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        for(int len = 2; len <= n; len ++) {
            for(int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                //include 
                int include_front = nums[i] - dp[i+1][j];
                int include_back = nums[j] - dp[i][j-1];

                dp[i][j] = max(include_front, include_back);
            }
        }
        return dp[0][n - 1];
    }

    // TC = O(N^2)
    // SC = O(N)
    int solveSOII(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr(n+1, 0);
        vector<int> prev(n+1, 0);

        // Analysizing base case
        for(int i = 0; i < n; i++) {
            prev[i] = nums[i];
        }

        for(int len = 2; len <= n; len ++) {
            for(int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                //include 
                int include_front = nums[i] - curr[j];
                int include_back = nums[j] - prev[j-1];
                prev[j] = max(include_front, include_back);
            }
            prev = curr;
        }
        return curr[n - 1];
    }

public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total_score = accumulate(nums.begin(), nums.end(), 0);

        // // Recursive Approach - 2 -> find out the difference b/w score of players
        // return solveRecII(0, n - 1, nums) >= 0;

        // // Recursion approach - 2 + Memoization
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveRecII_Mem(0, n - 1, nums, dp) >= 0;
    

        // //Tabulation
        // return solveTabII(nums) >= 0;


        // Space-Optimization
        return solveSOII(nums) >= 0;
    }
};
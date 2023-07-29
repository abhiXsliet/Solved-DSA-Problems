// https://leetcode.com/problems/predict-the-winner/



#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solveRecI(int i, int j, vector<int>& nums) {
        //base case
        if(i == j) return nums[i];
        if(i > j) return 0;

        //include 
        int include_front = nums[i] + min( solveRecI(i+2, j, nums), solveRecI(i+1, j-1, nums) );
        int include_back = nums[j] + min( solveRecI(i+1, j-1, nums), solveRecI(i, j-2, nums) );

        return max(include_front, include_back);
    }

    // TC = O(N^2)
    // SC = O(N^2)
    int solveRecI_Mem(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        //base case
        if(i == j) return nums[i];
        if(i > j) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        //include 
        int include_front = nums[i] + min( solveRecI_Mem(i+2, j, nums, dp), solveRecI_Mem(i+1, j-1, nums, dp) );
        int include_back = nums[j] + min( solveRecI_Mem(i+1, j-1, nums, dp), solveRecI_Mem(i, j-2, nums, dp) );

        return dp[i][j] = max(include_front, include_back);
    }

    int solveTabI(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp (n+1, vector<int>(n+1, 0));

        //analysizing base case
        for(int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        for(int len = 2; len <= n; len ++) {
            for(int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                //include 
                if( j-2 >= 0 ) {
                    int include_front = nums[i] + min( dp[i+2][j], dp[i+1][j-1] );
                    int include_back = nums[j] + min( dp[i+1][j-1], dp[i][j-2] );

                    dp[i][j] = max(include_front, include_back);
                }
            }
        }
        return dp[0][n - 1];
    }

public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total_score = accumulate(nums.begin(), nums.end(), 0);

        // int player1_score = solveRecI(0, n - 1, nums);
        // int player2_score = total_score - player1_score;
        // // Recursion
        // // return player1_score >= player2_score;
        

        // // Recursion + Memoization
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int player1_score = solveRecI_Mem(0, n - 1, nums, dp);
        // int player2_score = total_score - player1_score;
        // return player1_score >= player2_score;


        //Tabulation
        return solveTabI(nums) >= 0;
    }
};
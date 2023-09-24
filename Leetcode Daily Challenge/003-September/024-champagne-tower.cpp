// https://leetcode.com/problems/champagne-tower/


#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    // TC = O(N * N)
    // SC = O(N * N) where N = query_row
    double solve_mem(int poured, int i, int j, vector<vector<double>>& dp) {
        
        if (i < 0 || j < 0 || i < j) return 0.0;

        if (i == 0 && j == 0) // we reached top glass
            return poured;

        if (dp[i][j] != -1) return dp[i][j];
 
        double up_left  = ( solve_mem(poured, i - 1, j - 1, dp) - 1 ) / 2.0;
        double up_right = ( solve_mem(poured, i - 1, j    , dp) - 1 ) / 2.0;

        if (up_left  < 0) up_left  = 0.0;
        if (up_right < 0) up_right = 0.0;

        return dp[i][j] = (up_left + up_right);
    }

    // TC = O(N * N)
    // SC = O(N * N) where N = query_row
    double solve_tab(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 2, vector<double>(query_row + 2, 0.0));

        dp[0][0] = (double)poured;

        for (int row = 0; row <= query_row; row++) {
            for (int col = 0; col <= row; col++) {
                
                double extra = (dp[row][col] - 1) / 2.0;

                if (extra > 0) {
                    dp[row + 1][col]     += extra;
                    dp[row + 1][col + 1] += extra;
                }
            }
        }

        return min(1.0, dp[query_row][query_glass]);
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        // vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, -1));
        // return min(1.0, solve_mem(poured, query_row, query_glass, dp));


        // Tabulation
        return solve_tab(poured, query_row, query_glass);
    }
};
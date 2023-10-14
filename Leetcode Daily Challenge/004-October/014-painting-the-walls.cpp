// https://leetcode.com/problems/painting-the-walls/


#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    int solve_rec(vector<int>& cost, vector<int>& time, int idx, int wallToPaint) {
        
        if (wallToPaint <= 0  )
            return 0;   // no wall remains to paint

        if (idx >= cost.size())          
            return 1e9; // invalid case

        int paint    = cost[idx] + solve_rec(cost, time, idx+1, wallToPaint - 1 - time[idx]);
        int no_paint = solve_rec(cost, time, idx+1, wallToPaint);

        return min(paint, no_paint);
    }

    int solve_mem(vector<int>& cost, vector<int>& time, int idx, int wallToPaint, vector<vector<int>>& dp) {
        
        if (wallToPaint <= 0  )
            return 0;   // no wall remains to paint

        if (idx >= cost.size())          
            return 1e9; // invalid case

        if (dp[idx][wallToPaint] != -1) 
            return dp[idx][wallToPaint];

        int paint    = cost[idx] + solve_mem(cost, time, idx+1, wallToPaint - 1 - time[idx], dp);
        int no_paint = solve_mem(cost, time, idx+1, wallToPaint, dp);

        return dp[idx][wallToPaint] = min(paint, no_paint);
    }

    int solve_tab(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i = 1; i <= n; i++) {
            dp[n][i] = 1e9;
        }

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int wallToPaint = 1; wallToPaint <= n; wallToPaint++) {
                int paint    = cost[idx] + dp[idx+1][max(0, wallToPaint - 1 - time[idx])];
                int no_paint = dp[idx+1][wallToPaint];
                dp[idx][wallToPaint] = min(paint, no_paint);
            }
        }

        return dp[0][n];
    }


    int solve_so(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for (int i = 1; i <= n; i++) {
            curr[i] = 1e9;
        }

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int wallToPaint = 1; wallToPaint <= n; wallToPaint++) {
                int paint    = cost[idx] + curr[max(0, wallToPaint - 1 - time[idx])];
                int no_paint = curr[wallToPaint];
                next[wallToPaint] = min(paint, no_paint);
            }
            curr = next;
        }

        return curr[n];
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) { 
        int n = cost.size();
        // return solve_rec(cost, time, 0, n);

        // Recursion + Memoization
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solve_mem(cost, time, 0, n, dp);

        // Tabulation
        // return solve_tab(cost, time);

        // Space-Optimization
        return solve_so(cost, time);
    }
};
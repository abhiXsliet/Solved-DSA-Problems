// https://leetcode.com/problems/triangle/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m;
    int solve(vector<vector<int>> &tri, int i, int j, vector<vector<int>> &dp) {
        if (i == m - 1) return tri[i][j];

        if (dp[i][j] != -1) return dp[i][j];

        int op1 = solve(tri, i + 1, j, dp);
        int op2 = solve(tri, i + 1, j + 1, dp);

        return dp[i][j] = (tri[i][j] + min(op1, op2));
    }

    // TC : O(M * M)
    // SC : O(M * M)
    int top_down(vector<vector<int>> &triangle) {
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
        return solve(triangle, 0, 0, dp);
    }

    // TC : O(M * M)
    // SC : O(M * M)
    int bottom_up(vector<vector<int>> &tri) {
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        for (int j = 0; j < m; j ++) {
            dp[m - 1][j] = tri[m - 1][j];
        }

        for (int i = m - 2; i >= 0; i --) {
            for (int j = 0; j < tri[i].size(); j ++) {
                int op1 = dp[i + 1][j];
                int op2 = dp[i + 1][j + 1];

                dp[i][j] = (tri[i][j] + min(op1, op2));
            }
        }
        return dp[0][0];
    }

    // TC : O(M * M)
    // SC : O(M)
    int space_optimized(vector<vector<int>> &tri) {
        vector<int> prev(m + 1, 0);
        for (int j = 0; j < m; j ++) {
            prev[j] = tri[m - 1][j];
        }

        for (int i = m - 2; i >= 0; i --) {
            vector<int> curr(m + 1, 0);
            for (int j = 0; j < tri[i].size(); j ++) {
                int op1 = prev[j];
                int op2 = prev[j + 1];

                curr[j] = (tri[i][j] + min(op1, op2));
            }
            prev = curr;
        }
        return prev[0];
    }

    // TC : O(M * M)
    // SC : O(M)
    int space_optimized_optimal(vector<vector<int>> &tri) {
        vector<int> dp(tri[m - 1]); // initialize with the last row of the triangle
        for (int i = m - 2; i >= 0; i --) {
            for (int j = 0; j < tri[i].size(); j ++) {
                int op1 = dp[j];
                int op2 = dp[j + 1];
                dp[j]   = (tri[i][j] + min(op1, op2));
            }
        }
        return dp[0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        m = triangle.size();   
        // return top_down(triangle);
        // return bottom_up(triangle);
        // return space_optimized(triangle);
        return space_optimized_optimal(triangle);
    }
};
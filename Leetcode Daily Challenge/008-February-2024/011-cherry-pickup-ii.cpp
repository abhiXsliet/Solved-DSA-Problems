// https://leetcode.com/problems/cherry-pickup-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;
    int t[71][71][71];

    // TC : O(m * n * n * 9) ~= O(n^2 * m)
    // SC : O(n^2 * m)
    int solve_mem(vector<vector<int>>& grid, int row, int c1, int c2) {
        if (row >= m) return 0; // got no cherries as we are out of bound
        
        if (t[row][c1][c2] != -1) return t[row][c1][c2];
        
        int cherry = grid[row][c1];
        if (c1 != c2) { // cherry from same cell can be taken only once
            cherry += grid[row][c2];
        }

        int ans = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {

                int newRow = row + 1;
                int newC1  = c1 + i;
                int newC2  = c2 + j;

                if (newC1 >= 0 && newC1 < n && newC2 >= 0 && newC2 < n)
                    ans = max( ans, solve_mem(grid, newRow, newC1, newC2) );
            }
        }

        return t[row][c1][c2] = cherry + ans;
    }

    // TC : O(m * n^2)
    // SC : O(m * n^2)
    int solve_tab(vector<vector<int>>& grid) {
        int t[71][71][71] = {0};
        // t[row][c1][c2] = Max Cherry Collected till row + c1 by robot-1 + row + c2 by robot-2

        t[0][0][n - 1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n - 1];

        for (int row = 1; row < m; row ++) {
            
            for (int c1 = 0; c1 <= min(n - 1, row); c1 ++) {
                
                for (int c2 = max(0, n - row - 1); c2 < n; c2 ++) {

                    int prevRowMax = 0;

                    for (int prevC1 = max(0, c1 - 1); prevC1 <= min(n - 1, c1 + 1); prevC1 ++) {

                        for (int prevC2 = max(0, c2 - 1); prevC2 <= min(n - 1, c2 + 1); prevC2 ++) {

                            prevRowMax = max(prevRowMax, t[row - 1][prevC1][prevC2]);
                        }
                    }

                    if (c1 == c2) {
                        t[row][c1][c2] = prevRowMax + grid[row][c1];
                    }
                    else {
                        t[row][c1][c2] = prevRowMax + grid[row][c1] + grid[row][c2];
                    }
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, t[m - 1][i][j]);
            }
        }

        return result;
    }

    // TC : O(m * n^2)
    // SC : O(m * n)
    int solve_so(vector<vector<int>>& grid) {
        vector<vector<int>> prev(n+1, vector<int>(n+1, 0));

        prev[0][n - 1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n - 1];

        for (int row = 1; row < m; row ++) {
            
            vector<vector<int>> curr(n+1, vector<int>(n+1, 0));
            
            for (int c1 = 0; c1 <= min(n - 1, row); c1 ++) {
                
                for (int c2 = max(0, n - row - 1); c2 < n; c2 ++) {

                    int prevRowMax = 0;

                    for (int prevC1 = max(0, c1 - 1); prevC1 <= min(n - 1, c1 + 1); prevC1 ++) {

                        for (int prevC2 = max(0, c2 - 1); prevC2 <= min(n - 1, c2 + 1); prevC2 ++) {

                            prevRowMax = max(prevRowMax, prev[prevC1][prevC2]);
                        }
                    }

                    if (c1 == c2) {
                        curr[c1][c2] = prevRowMax + grid[row][c1];
                    }
                    else {
                        curr[c1][c2] = prevRowMax + grid[row][c1] + grid[row][c2];
                    }
                }
            }

            prev = curr;
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, prev[i][j]);
            }
        }

        return result;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // memset(t, -1, sizeof(t));
        // return solve_mem(grid, 0, 0, n - 1);

        // return solve_tab(grid);

        return solve_so(grid);
    }
};
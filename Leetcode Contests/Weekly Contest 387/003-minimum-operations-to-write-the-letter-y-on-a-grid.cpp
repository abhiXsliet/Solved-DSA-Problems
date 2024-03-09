// https://leetcode.com/contest/weekly-contest-387/problems/minimum-operations-to-write-the-letter-y-on-a-grid/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N^2)
    // SC : O(1)
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int y_0 = 0;  // zeros inside cells of y
        int y_1 = 0;  // ones inside cells of y
        int y_2 = 0;  // twos inside cells of y
        
        // top-left to center
        for (int i = 0; i <= n / 2; i++) {
            if (grid[i][i] == 0) y_0 ++;
            if (grid[i][i] == 1) y_1 ++;
            if (grid[i][i] == 2) y_2 ++;
        }
        
        // top-right to center
        for (int i = 0; i < n / 2; i++) {
            if (grid[i][n - 1 - i] == 0) y_0 ++;
            if (grid[i][n - 1 - i] == 1) y_1  ++;
            if (grid[i][n - 1 - i] == 2) y_2  ++;
        }
        
        // vertical line from the center + 1 (downward)
        for (int i = n / 2 + 1; i < n; i++) {
            if (grid[i][n/2] == 0) y_0 ++;
            if (grid[i][n/2] == 1) y_1  ++;
            if (grid[i][n/2] == 2) y_2  ++;
        }
        
        // Total zeros, ones, twos in matrix
        int zeros = 0;
        int ones  = 0;
        int twos  = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) zeros ++;
                if (grid[i][j] == 1) ones  ++;
                if (grid[i][j] == 2) twos  ++;
            }
        }
        
        int out_y_0 = zeros - y_0;
        int out_y_1 = ones  - y_1;
        int out_y_2 = twos  - y_2;

        // include 0 into y
        int min_1 = y_1 + y_2 + min(out_y_1, out_y_2) + out_y_0;
        // include 1 into y
        int min_2 = y_0 + y_2 + min(out_y_0, out_y_2) + out_y_1;
        // include 2 into y
        int min_3 = y_0 + y_1 + min(out_y_0, out_y_1) + out_y_2;
        
        return min(min(min_1, min_2), min_3);
    }
};
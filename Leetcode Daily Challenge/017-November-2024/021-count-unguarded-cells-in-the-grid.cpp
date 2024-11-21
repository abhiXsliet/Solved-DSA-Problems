// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void markGuarded(int r, int c, vector<vector<int>>& grid) {
        // Mark Guarded in UP
        for (int i = r - 1; i >= 0; i --) {
            if (grid[i][c] == 2 || grid[i][c] == 3)
                break;
            grid[i][c] = 1;
        }

        // Mark Guarded in DOWN
        for (int i = r + 1; i < grid.size(); i ++) {
            if (grid[i][c] == 2 || grid[i][c] == 3)
                break;
            grid[i][c] = 1;
        }

        // Mark Guarded in Left
        for (int j = c - 1; j >= 0; j --) {
            if (grid[r][j] == 2 || grid[r][j] == 3)
                break;
            grid[r][j] = 1;
        }

        // Mark Guarded in right
        for (int j = c + 1; j < grid[0].size(); j ++) {
            if (grid[r][j] == 2 || grid[r][j] == 3)
                break;
            grid[r][j] = 1; 
        }
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int approach_1(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Fill '2' for all the guards
        for (vector<int>& guard : guards) {
            int r = guard[0];
            int c = guard[1];
            grid[r][c] = 2;
        }

        // Fill '3' for all the walls
        for (vector<int>& wall : walls) {
            int r = wall[0];
            int c = wall[1];
            grid[r][c] = 3;
        }

        // Fill '1' for all the cells which can be guarded
        for (vector<int>& guard : guards) {
            int i = guard[0];
            int j = guard[1];
            markGuarded(i, j, grid);
        }

        int unguardedCnt = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 0) {
                    unguardedCnt += 1;
                }
            }
        }
        return unguardedCnt;
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        return approach_1(m, n, guards, walls); // Iterative Appraoch

                                                // Recursive Approach : Pending?
    }   
};
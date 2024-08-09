// https://leetcode.com/problems/magic-squares-in-grid/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(3)
    // SC : O(3*3)
    bool isMagical(vector<vector<int>>& grid, int r, int c) {
        // 1st Check : All no.s should be from 1 to 9 and unique only
        unordered_set<int> st;
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                int num = grid[r + i][c + j];
                if (num < 1 || num > 9 || st.count(num)) {
                    return false;
                } else {
                    st.insert(num);
                }
            }
        }

        // 2nd Check : All rows and cols sum should be equal
        int S = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

        for (int i = 0; i < 3; i ++) {
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != S)
                return false;

            if (grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != S)
                return false;
        }

        // 3rd Check : Diagonal and Anti-Diagonal Sum should be equal
        int diagSum  = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
        if (diagSum != S) return false;

        int antiDiagSum  = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];
        if (antiDiagSum != S) return false;

        return true;
    }

    // TC : O(rows * cols)
    // SC : O(1)
    int brute(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int subMatCnt = 0;
        for (int i = 0; i <= rows - 3; i ++) {
            for (int j = 0; j <= cols - 3; j ++) {
                if (isMagical(grid, i, j)) 
                    subMatCnt ++;
            }
        }
        return subMatCnt;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        return brute(grid);
    }
};
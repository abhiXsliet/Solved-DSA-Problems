// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int row = 0, col = n - 1;
        int cntNeg = 0;
        while (row < m && col >= 0) {
            if (grid[row][col] < 0) {
                cntNeg += (m - row);
                col --;
            } else row ++;
        }
        return cntNeg;
    }
};
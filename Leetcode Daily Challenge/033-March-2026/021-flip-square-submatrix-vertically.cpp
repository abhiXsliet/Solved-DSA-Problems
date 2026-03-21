// https://leetcode.com/problems/flip-square-submatrix-vertically/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size(), n = grid[0].size();
        
        int top = x;
        int bottom = x + k - 1;

        while (top < bottom) {
            for (int j = y; j <= y + k - 1; j ++) {
                swap(grid[top][j], grid[bottom][j]);
            }
            top ++;
            bottom --;
        }

        return grid;
    }
};
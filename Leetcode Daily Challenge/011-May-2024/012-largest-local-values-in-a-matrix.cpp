// https://leetcode.com/problems/largest-local-values-in-a-matrix/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N^2)
    // SC : O(1)
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n - 2, vector<int>(n - 2));
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {

                int val = INT_MIN;
                for (int k = i; k < i + 3; k ++) {
                    for (int l = j; l < j + 3; l ++) {
                        val = max(val, grid[k][l]);
                    }
                }

                result[i][j] = val;
            }
        }
        return result;
    }
};
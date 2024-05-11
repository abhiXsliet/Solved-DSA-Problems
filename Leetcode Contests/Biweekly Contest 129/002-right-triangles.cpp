// https://leetcode.com/contest/biweekly-contest-129/problems/right-triangles/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*M)
    // SC : O(N + M)
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row(m, 0), col(n, 0);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        long long triangles = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    triangles += (long long)(row[i] - 1) * (col[j] - 1);
                }
            }
        }
        
        return triangles;
    }
};

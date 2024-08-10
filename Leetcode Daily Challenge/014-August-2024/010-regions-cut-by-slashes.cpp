// https://leetcode.com/problems/regions-cut-by-slashes/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    // TC : O(M * N) at worst
    // SC : O(1)
    void DFS(int i, int j, int m, int n, vector<vector<int>>& mat) {
        if (i < 0 || i >= m || j < 0 || j >= n || mat[i][j] == 1)
            return;

        mat[i][j] = 1;  // mark visited 

        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            DFS(i_, j_, m, n, mat);
        }
    }
public:
    // TC : O(M * N) visiting every cell once only
    // SC : O(M * N)
    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size();    // rows
        int n = grid[0].size(); // cols

        vector<vector<int>> mat(m*3, vector<int>(n*3, 0));

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {

                if (grid[i][j] == '\\') {
                    mat[i*3][j*3]     = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3+2] = 1;

                } else if (grid[i][j] == '/') {
                    mat[i*3][j*3+2]   = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3]   = 1;
                }

            }
        }

        int regionsCnt = 0;
        m = 3*m;
        n = 3*n;

        // Hit DFS from 0 and calculate no.s of region
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {

                if (mat[i][j] == 0) {
                    DFS(i, j, m, n, mat);
                    regionsCnt ++;
                }

            }
        }

        return regionsCnt;
    }
};
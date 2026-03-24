// https://leetcode.com/problems/construct-product-matrix/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int M = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> res(m, vector<int>(n, 1));
        long long prefix = 1, suffix = 1;

        // calculating suffix similar to 1-D array and storing into 'p'
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                res[i][j] = (suffix * res[i][j]) % M;
                suffix    = (suffix * grid[i][j]) % M;
            }
        }

        // calculating prefix on the go
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                res[i][j] = (prefix * res[i][j]) % M;
                prefix    = (prefix * grid[i][j]) % M;
            }
        }

        return res;
    }
};
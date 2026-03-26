// https://leetcode.com/problems/equal-sum-grid-partition-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;
    ll total = 0;

    bool checkHorCuts(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<ll> st;
        ll top = 0;

        for (int i = 0; i <= m - 2; i ++) {
            for (int j = 0; j < n; j ++) {
                top += grid[i][j];
                st.insert(grid[i][j]);
            }
            ll bottom = total - top;
            ll diff = top - bottom;

            if (diff == 0) return true;
            if (diff == (ll)grid[0][0] || diff == (ll)grid[0][n - 1]) return true;
            if (diff == (ll)grid[i][0]) return true;
            if (i > 0 && n > 1 && st.count(diff)) return true;
        }

        return false;
    }
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                total += grid[i][j];
            }
        }

        if (checkHorCuts(grid)) return true;
        reverse(begin(grid), end(grid));
        if (checkHorCuts(grid)) return true;

        // original grid
        reverse(begin(grid), end(grid));

        // Transpose
        vector<vector<int>> tMat(n, vector<int>(m, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                tMat[j][i] = grid[i][j];
            }
        }

        if (checkHorCuts(tMat)) return true;
        reverse(begin(tMat), end(tMat));
        if (checkHorCuts(tMat)) return true;

        return false;
    }
};
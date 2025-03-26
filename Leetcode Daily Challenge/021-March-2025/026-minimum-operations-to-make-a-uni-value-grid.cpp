// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;

    // TC : O(M*N * log(M*N))
    // SC : O(M*N)
    int approach_1(vector<vector<int>> &grid, int x) {
        vector<int> store;
        int rem = -1;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (rem != -1 && rem != (grid[i][j] % x)) {
                    return -1;
                }
                rem = (grid[i][j] % x);
                store.push_back(grid[i][j]);
            }
        }

        sort(begin(store), end(store));

        int cntOperations = 0;
        int optimalEle = store[(m*n)/2];

        for (int &val : store) {
            cntOperations += (abs(val - optimalEle) / x);
        }

        return cntOperations;
    }
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        m = grid.size(), n = grid[0].size();

        return approach_1(grid, x); 
    }
};
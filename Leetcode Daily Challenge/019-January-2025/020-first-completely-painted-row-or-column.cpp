// https://leetcode.com/problems/first-completely-painted-row-or-column/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M * N)
    // SC : O((M * N) + (M + N))
    int approach_1(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int size = m * n;

        // store each unique value's row and its col of mat
        unordered_map<int, pair<int, int>> mpp;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                mpp[mat[i][j]] = {i, j};
            }
        }

        unordered_map<int, int> rowMpp, colMpp;
        for (int i = 0; i < size; i ++) {
            int r = mpp[arr[i]].first;
            int c = mpp[arr[i]].second;
            rowMpp[r] ++;
            colMpp[c] ++;
            if (rowMpp[r] == n || colMpp[c] == m) {
                return i;
            }
        }
        return size - 1;
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int approach_2(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int size = m * n;
        unordered_map<int, int> indices;
        for (int i = 0; i < size; i ++) {
            indices[arr[i]] = i;
        }

        int minIdx = size - 1;
        for (int i = 0; i < m; i ++) {
            int row_i_idx = 0;
            for (int j = 0; j < n; j ++) {
                row_i_idx = max(row_i_idx, indices[mat[i][j]]);
            }
            minIdx = min(minIdx, row_i_idx);
        }
        for (int j = 0; j < n; j ++) {
            int col_i_idx = 0;
            for (int i = 0; i < m; i ++) {
                col_i_idx = max(col_i_idx, indices[mat[i][j]]);
            }
            minIdx = min(minIdx, col_i_idx);
        }
        return minIdx;
    }
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // return approach_1(arr, mat);

        return approach_2(arr, mat);     // optimized space a little
    }
};
// https://leetcode.com/problems/last-day-where-you-can-still-cross/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    bool bfs(int i, int j, vector<vector<int>> &mat, int row, int col) {
        queue<pair<int, int>> q;
        q.push({i, j});
        mat[i][j] = 1;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int i = it.first;
            int j = it.second;

            if (i == row - 1) return true;

            for (auto &dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                if (i_ >= 0 && i_ < row && j_ >= 0 && j_ < col && !mat[i_][j_]) {
                    q.push({i_, j_});
                    mat[i_][j_] = 1;    // mark-water (catch)
                }
            }
        }
        return false;
    }

    bool dfs(int i, int j, vector<vector<int>> &mat, int row, int col) {
        if (i < 0 || i >= row || j < 0 || j >= col || mat[i][j]) return false;
        if (i == row - 1) return true;

        mat[i][j] = 1;  // mark-path

        for (auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (dfs(i_, j_, mat, row, col)) {
                return true;
            }
        }
        return false;
    }

    bool isPossible(vector<vector<int>> &cells, int row, int col, int mid) {
        vector<vector<int>> mat(row, vector<int>(col, 0));  // all land cells
        
        for (int i = 0; i <= mid; i ++) {
            int x = cells[i][0] - 1, y = cells[i][1] - 1;
            mat[x][y] = 1;  
        }

        for (int c = 0; c < col; c ++) {
            // if (!mat[0][c] && dfs(0, c, mat, row, col)) return true;
            if (!mat[0][c] && bfs(0, c, mat, row, col)) return true;
        }
        return false;
    }
public:
    // TC : O(N*log(N)) where N = row * col
    // SC : O(row * col)
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0, high = cells.size() - 1;
        int ans = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(cells, row, col, mid)) {
                ans = mid + 1;  // 1-based indexing
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans; 
    }
};
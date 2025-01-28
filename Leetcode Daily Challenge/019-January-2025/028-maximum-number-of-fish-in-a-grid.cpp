// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/



#include <bits/stdc++.h>
using namespace std;

class DSU {
    private:
        vector<int> parent;
        vector<int> rank; // stores the cnt of fishes at respective cells of grid[i][j]
        int size;
    public:
    DSU(int n) {
        size = n;
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i ++) {
            rank[i]   = 0;    // initially fishes counts are zero
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = findParent(parent[x]);   // path compression
    }

    void findUnion(int x, int y) {
        int x_parent = findParent(x);
        int y_parent = findParent(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
            rank[x_parent]  += rank[y_parent];
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]  += rank[x_parent];
        }
    }

    void setSizeOfRank(int i, int fishCnt) {
        rank[i] = fishCnt;
    }

    int getMaxFishCnt() {
        return *max_element(begin(rank), end(rank));
    }
};

class Solution {
private:
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // TC : O(M * N)
    // SC : O(M * N)
    int BFS(int i, int j, int m, int n, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        int collectFish = grid[i][j];
        grid[i][j] = 0;
        while (!q.empty()) {
            auto P = q.front();
            int  x = P.first;
            int  y = P.second;
            q.pop();
            for (auto& dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                if (x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && grid[x_][y_]) {
                    collectFish += grid[x_][y_];
                    q.push({x_, y_});
                    grid[x_][y_] = 0;
                }
            }
        }
        return collectFish;
    }
    
    // TC : O(M * N)
    // SC : O(M * N) max recursive depth
    int DFS(int i, int j, int m, int n, vector<vector<int>>& grid) {
        int collect = grid[i][j];
        grid[i][j]  = 0;
        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_]) {
                collect += DFS(i_, j_, m, n, grid);
            }
        }
        return collect;
    }

    // TC : O(M * N)
    // SC : O(1)
    int approach_1(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxFish = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j]) {
                    maxFish = max(maxFish, DFS(i, j, m, n, grid));
                }
            }
        }
        return maxFish;
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int approach_2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxFish = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j]) {
                    maxFish = max(maxFish, BFS(i, j, m, n, grid));
                }
            }
        }
        return maxFish;
    }

    // The findParent() operation uses path compression, making it run in O(α(m × n)), where α (Ackermann's inverse function) is nearly O(1) in practice. 
    // Hence, the union operations contribute O(m × n α(m × n)), which simplifies to O(m × n)
    // TC : O(M * N)
    // SC : O(M * N)
    int approach_3(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int totalSize = m * n;

        DSU dsu(totalSize);

        // Initialize the rank array with initial fish count of grid
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j]) {
                    int index = n * i + j;  // 1-D array index corresponding to grid
                    dsu.setSizeOfRank(index, grid[i][j]);
                }
            }
        }

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int idx = n * i + j;
                if (grid[i][j]) {
                    for (auto& dir : directions) {
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];
                        if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_]) {
                            int idx_ = n * i_ + j_;
                            dsu.findUnion(idx, idx_);
                        }
                    }
                }
            }
        }
        return dsu.getMaxFishCnt();
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        // return approach_1(grid);    // DFS
        // return approach_2(grid);    // BFS
        return approach_3(grid);    // DSU
    }
};
// https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;
    typedef vector<int> V;
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool inBound(int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    int bfs_optimized(vector<vector<int>> &grid, priority_queue<V, vector<V>, greater<V>> &pq, vector<vector<bool>> &visited, int &points, int target) {
        while (!pq.empty()) {
            int val = pq.top()[0];
            int i   = pq.top()[1];
            int j   = pq.top()[2];
            
            if (val >= target) return points;

            points += 1;
            pq.pop();

            for (auto &dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                
                if (inBound(i_, j_) && !visited[i_][j_]) {
                    pq.push({grid[i_][j_], i_, j_});
                    visited[i_][j_] = 1;
                }
            }
        }

        return points;
    }

    int dfs(int i, int j, vector<vector<int>> &grid, int target, vector<vector<bool>> &visited) {
        if (!inBound(i, j) || visited[i][j] || grid[i][j] >= target) 
            return 0;

        visited[i][j] = 1;
        int points = 1;

        for (auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            points += dfs(i_, j_, grid, target, visited);
        }

        return points;
    }

    int bfs(vector<vector<int>> &grid, int target) {
        if (grid[0][0] >= target) return 0;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        q.push({0, 0});
        visited[0][0] = 1;

        int points = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int i = it.first;
            int j = it.second;
            points ++;

            for (auto & dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (inBound(i_, j_) && !visited[i_][j_] && grid[i_][j_] < target) {
                    q.push({i_, j_});
                    visited[i_][j_] = 1;
                }
            }            
        }
        return points;
    }

    // TC : O(M * N * K)
    // SC : O(M * N) space used by visited matrix
    vector<int> approach_1(vector<vector<int>> &grid, vector<int> &queries) {
        int k = queries.size();
        vector<int> result;
        for (int &query : queries) {
            result.push_back(bfs(grid, query));
        }
        return result;
    }

    // TC : O(M * N * K)
    // SC : O(M * N) space used by visited matrix
    vector<int> approach_2(vector<vector<int>> &grid, vector<int> &queries) {
        int k = queries.size();
        vector<int> result;
        for (int &query : queries) {
            vector<vector<bool>> visited(m, vector<bool>(n, 0));
            result.push_back(dfs(0, 0, grid, query, visited));
        }
        return result;
    }

    // TC : O(Klog(K) + MN*log(MN))
    // SC : O(M * N) space used by visited matrix
    vector<int> approach_3(vector<vector<int>> &grid, vector<int> &queries) {
        int k = queries.size();
        
        vector<pair<int, int>> newQ;
        for (int i = 0; i < k; i ++) {
            newQ.push_back({queries[i], i});
        }

        sort(begin(newQ), end(newQ));

        int points = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        priority_queue<V, vector<V>, greater<V>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;

        vector<int> result(k);
        for (auto &q : newQ) {
            int idx   = q.second;
            int query = q.first;

            result[idx] = bfs_optimized(grid, pq, visited, points, query);
        }
        return result;
    }
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        m = grid.size(), n = grid[0].size();

        // return approach_1(grid, queries);   // BFS : TLE
        // return approach_2(grid, queries);   // DFS : TLE
        return approach_3(grid, queries);   // BFS : optimized sorting queries and reusing prev result
    }
};
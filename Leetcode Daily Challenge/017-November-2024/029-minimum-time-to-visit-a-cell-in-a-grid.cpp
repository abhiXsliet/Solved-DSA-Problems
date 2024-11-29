// https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    // TC : O(E * log(V))
    // SC : O(V + E)         Where V = M * N & E = M * N
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        pq.push({0, {0, 0}});
        result[0][0]  = 0;

        while (!pq.empty()) {
            int time = pq.top().first;
            int i    = pq.top().second.first;
            int j    = pq.top().second.second;
            pq.pop();

            if (i == m - 1 && j == n - 1)
                return result[m - 1][n - 1];

            if (visited[i][j] == 1) continue;

            visited[i][j] = 1;

            for (auto& dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                
                if (i_ < 0 || i_ >= m || j_ < 0 || j_ >= n)   
                    continue;
                
                if (grid[i_][j_] <= time) {
                    pq.push({time + 1, {i_, j_}});
                    result[i_][j_] = time + 1;
                } else if ((grid[i_][j_] - time) % 2 == 0) {
                    pq.push({grid[i_][j_] + 1, {i_, j_}});
                    result[i_][j_] = grid[i_][j_] + 1;
                } else {
                    pq.push({grid[i_][j_], {i_, j_}});
                    result[i_][j_] = grid[i_][j_];
                }
            }
        }
        return result[m - 1][n - 1];
    }
};
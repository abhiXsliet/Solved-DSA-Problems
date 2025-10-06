// https://leetcode.com/problems/swim-in-rising-water/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        // Min-heap (time, x, y)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int time = top[0];
            int x = top[1];
            int y = top[2];

            // reached destination
            if (x == n - 1 && y == n - 1) 
                return time;

            if (vis[x][y]) continue;
            vis[x][y] = true;

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                    int newTime = max(time, grid[nx][ny]);
                    pq.push({newTime, nx, ny});
                }
            }
        }

        return -1; // should never reach here
    }
};
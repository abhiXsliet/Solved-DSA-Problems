// https://leetcode.com/problems/shortest-path-in-binary-matrix/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, pair<int, int>> P; // dist, {x-coor, y-coor}
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

    // TC = O(M * N)
    // SC = O(M * N)
    int solve_bfs(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 0 || n == 0 || grid[0][0] != 0) 
            return -1;
        
        queue<pair<int, int>> q;
        q.push({0, 0});

        grid[0][0] = 1;
        
        int level = 0;

        auto isSafe = [&](int x, int y) {
            return ( x >= 0 && x < m && y >= 0 && y < n );
        };

        while(!q.empty()) {
            int N = q.size();

            while(N--) {
                auto pair = q.front();
                q.pop();

                int x = pair.first;
                int y = pair.second;

                if (x == m - 1 && y == n - 1)
                    return level + 1;

                for (auto& dir : directions) {
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];

                    if (isSafe(new_x, new_y) && grid[new_x][new_y] == 0) {
                        q.push({new_x, new_y});
                        grid[new_x][new_y] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    
    // TC = O(M * N * log(M * N))
    // SC = O(M * N)
    int solve_dijkstras(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (n == 0 || m == 0 || grid[0][0] != 0) 
            return -1;

        auto isSafe = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n);
        };

        // distance array for shortest path calculation
        vector<vector<int>> distArray(m, vector<int>(n, INT_MAX));
        
        // min heap to track the minimum distance
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0, 0}}); // to reach (0, 0) with dist of 0
        distArray[0][0] = 0;

        while(!pq.empty()) {
            
            int dist = pq.top().first;
            pair<int, int> p = pq.top().second;
            pq.pop();

            int x = p.first;
            int y = p.second;

            for (auto dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                int distance = 1;

                // not out of bound, visit allowed, dist + distance < distArray[new_x][new_y]
                if(isSafe(new_x, new_y) && grid[new_x][new_y] == 0 
                    && dist + distance < distArray[new_x][new_y]) { 
                    
                    pq.push({dist+distance, {new_x, new_y}});
                    
                    // does not matter since we are prior doing -> dist + distance < distArray[new_x][new_y]
                    grid[new_x][new_y] = 1; 

                    distArray[new_x][new_y] = dist + distance;
                }
            }
        }

        if (distArray[n - 1][m - 1] == INT_MAX) return -1;
        else return distArray[m - 1][n - 1] + 1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // return solve_bfs(grid);

        return solve_dijkstras(grid);
    }
};
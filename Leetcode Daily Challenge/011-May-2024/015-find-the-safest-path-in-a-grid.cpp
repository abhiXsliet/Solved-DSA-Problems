// https://leetcode.com/problems/find-the-safest-path-in-a-grid/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool check(vector<vector<int>>& distToNearestThief, int n, int sf) {
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        q.push({0, 0}); // {0, 0} ---> {n - 1, n - 1}
        vis[0][0] = true;

        if (distToNearestThief[0][0] < sf)
            return false;

        while (!q.empty()) {
            int curr_i = q.front().first;
            int curr_j = q.front().second;
            q.pop();

            if (curr_i == n - 1 && curr_j == n - 1) {
                return true;
            }

            for (vector<int>& dir : directions) {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];

                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && !vis[new_i][new_j]) {
                    if (distToNearestThief[new_i][new_j] < sf) {
                        continue;
                    }
                    q.push({new_i, new_j});
                    vis[new_i][new_j] = true;
                }
            }
        }
        return false;
    }
public:
    // TC : O(N^2 * log(N))
    // SC : O(N^2)
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // Step - 1 : Pre-calculation of nearest distance of thief - for each cell using BFS
        vector<vector<int>> distToNearestThief(n, vector<int>(n, -1));
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        // Pushing all the cells of thief into queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        // Step - 2 : Multisource BFS
        int level = 0;
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int curr_i = q.front().first;
                int curr_j = q.front().second;
                q.pop();

                distToNearestThief[curr_i][curr_j] = level;

                for (vector<int>& dir : directions) {
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];

                    if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || vis[new_i][new_j]) {
                        continue;
                    }

                    q.push({new_i, new_j});
                    vis[new_i][new_j] = true;
                }
            }
            level += 1;
        }

        // Step - 3 : Apply BS of safeness factor with optimized range
        int lo = 0, hi = 400, result = 0;
        while (lo <= hi) {
            int mid_sf = lo + (hi - lo) / 2; // safeness factor

            if (check(distToNearestThief, n, mid_sf)) {
                result = mid_sf;
                lo = mid_sf + 1;
            } else {
                hi = mid_sf - 1;
            }
        }

        return result;
    }
};
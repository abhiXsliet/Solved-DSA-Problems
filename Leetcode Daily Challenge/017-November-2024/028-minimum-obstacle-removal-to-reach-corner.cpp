// https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, int> P;
    const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void createGraph(vector<vector<int>>& grid, vector<vector<P>>& adj) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int node = i * n + j; // Map 2D index to 1D node index

                for (auto& dir : directions) {
                    int ni = i + dir[0]; 
                    int nj = j + dir[1]; 

                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        int neighbor = ni * n + nj;
                        int cost = grid[ni][nj];
                        adj[node].push_back({neighbor, cost}); 
                    }
                }
            }
        }
    }

    // TC : O(M * N * (log(M * N)))
    // SC : O(M * N)
    int dijkstras(int n, vector<vector<P>>& adj) {
        vector<int> dist(n, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0}); // {distance, node}
        dist[0] = 0;

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == n - 1) {
                return d; 
            }

            for (auto& nbr : adj[node]) {
                int adjNode = nbr.first;
                int wt = nbr.second;

                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return -1;
    }

    // TC : O(M * N) + (M * N * (log(M * N)))
    // SC : O(M * N)
    int approach_1(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<P>> adj(m * n); // Use vector for adjacency list
        createGraph(grid, adj);

        return dijkstras(m * n, adj);
    }

    // TC : O(E * log(V))
    // SC : O(E + V)
    int approach_2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> pq;
        pq.push({0, {0, 0}});   // {wt, {i, j}}
        result[0][0] = 0;

        while (!pq.empty()) {
            auto topNode = pq.top();
            pq.pop();

            int dist = topNode.first;
            int i    = topNode.second.first;
            int j    = topNode.second.second;

            for (auto& dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ < 0 || i_ >= m || j_ < 0 || j_ >= n) 
                    continue;
                
                int wt = (grid[i_][j_] == 1) ? 1 : 0;
                if (dist + wt < result[i_][j_]) {
                    result[i_][j_] = dist + wt;
                    pq.push({result[i_][j_], {i_, j_}});
                }
            }
        }

        return result[m - 1][n - 1];
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        // return approach_1(grid);    // 1-D Dijkstras Implementation

        return approach_2(grid);    // 2-D Dijkstras Implementation
                                    // Pending : BFS
    }
};
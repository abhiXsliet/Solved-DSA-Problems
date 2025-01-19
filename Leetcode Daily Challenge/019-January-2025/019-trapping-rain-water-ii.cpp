// https://leetcode.com/problems/trapping-rain-water-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // TC : O(M * N * log(M*N))
    // SC : O(M * N)
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();

        priority_queue<P, vector<P>, greater<>> pq;        // min-heap {height, {i, j}}
        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        // Inserting all cells of {0, n - 1} columns (i.e., leftmost and rightmost)
        for (int row = 0; row < m; row ++) {
            for (int col : {0, n - 1}) {
                pq.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        // Inserting all cells of {0, m - 1} rows (i.e., topmost and bottommost)
        for (int col = 0; col < n; col ++) {
            for (int row : {0, m - 1}) {
                pq.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        int maxWater = 0;
        while (!pq.empty()) {
            P topNode = pq.top();
            pq.pop();

            int height = topNode.first;
            int i      = topNode.second.first;
            int j      = topNode.second.second;

            for (vector<int>& vec : directions) {
                int i_ = i + vec[0];
                int j_ = j + vec[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                    maxWater += max(height - heightMap[i_][j_], 0);
                    pq.push({max(height, heightMap[i_][j_]), {i_, j_}});
                    visited[i_][j_] = true;
                }
            }
        }
        return maxWater;
    }
};
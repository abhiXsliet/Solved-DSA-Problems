// https://leetcode.com/problems/map-of-highest-peak/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:    
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // TC : O(M + N)
    // SC : O(M + N)
    vector<vector<int>> approach_1(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> result(m, vector<int>(n, -1));

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (isWater[i][j]) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            auto it = q.front();
            int i   = it.first;
            int j   = it.second;
            q.pop();

            for (auto& dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && result[i_][j_] == -1) {
                    result[i_][j_]  = result[i][j] + 1;
                    q.push({i_, j_});
                }
            }
        }

        return result;
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        return approach_1(isWater); // BFS : Optimal Approach
                                    // DFS : Not Optimal since assignment of height in depth goes wrong
    }
};
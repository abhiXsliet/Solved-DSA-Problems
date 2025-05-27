// https://leetcode.com/problems/grid-teleportation-traversal/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    // TC : O(M * N * log(M * N))
    // SC : O(M * N)
    int minMoves(vector<string>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        unordered_map<char, vector<pair<int, int>>> charPositions;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = matrix[i][j];
                if (c >= 'A' && c <= 'Z') {
                    charPositions[c].emplace_back(i, j);
                }
            }
        }

        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        vector<bool> visitedChars(26, false);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        distance[0][0] = 0;

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int currentDist = current.first;
            int i = current.second.first;
            int j = current.second.second;

            if (i == m - 1 && j == n - 1) {
                return currentDist;
            }

            if (currentDist > distance[i][j]) {
                continue;
            }

            char c = matrix[i][j];
            if (c >= 'A' && c <= 'Z' && !visitedChars[c - 'A']) {
                visitedChars[c - 'A'] = true;
                for (const auto& pos : charPositions[c]) {
                    int new_i = pos.first;
                    int new_j = pos.second;
                    if (distance[new_i][new_j] > currentDist) {
                        distance[new_i][new_j] = currentDist;
                        pq.push({currentDist, {new_i, new_j}});
                    }
                }
            }

            for (const auto& dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                if (isValid(new_i, new_j, m, n)) {
                    char new_c = matrix[new_i][new_j];
                    if (new_c == '#' || (new_c >= 'A' && new_c <= 'Z' && visitedChars[new_c - 'A'])) {
                        continue;
                    }
                    int newDist = currentDist + 1;
                    if (newDist < distance[new_i][new_j]) {
                        distance[new_i][new_j] = newDist;
                        pq.push({newDist, {new_i, new_j}});
                    }
                }
            }
        }

        return distance[m - 1][n - 1] == INT_MAX ? -1 : distance[m - 1][n - 1];
    }
};
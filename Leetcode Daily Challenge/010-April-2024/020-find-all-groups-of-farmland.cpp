// https://leetcode.com/problems/find-all-groups-of-farmland/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    // TC : O(M * N)
    // SC : O(M * N) -> Queue
    void bfs(vector<vector<int>>& land, int i, int j, int& r2, int& c2, int m, int n) {
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            r2 = max(it.first , r2);
            c2 = max(it.second, c2);

            for (auto& dir : directions) {
                int i_ = it.first  + dir[0];
                int j_ = it.second + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && land[i_][j_]) {
                    land[i_][j_] = 0;   // visited
                    q.push({i_, j_});
                }
            }
        }
    }

    // TC : O(M * N)
    // SC : O(M * N) -> Recursive Depth
    void dfs(vector<vector<int>>& land, int i, int j, int& r2, int& c2, int m, int n) {
        land[i][j] = 0;

        r2 = max(i, r2);
        c2 = max(j, c2);

        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && land[i_][j_] == 1)
                dfs(land, i_, j_, r2, c2, m, n);
        }
    }

    // TC : O(M * N)
    // SC : O(M * N) -> Depth of Recursion
    vector<vector<int>> approach_1(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        
        vector<vector<int>> result;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    int r1 = i;
                    int c1 = j;
                    int r2 = -1;
                    int c2 = -1;
                    dfs(land, i, j, r2, c2, m, n);
                    result.push_back({r1, c1, r2, c2});
                }
            }
        }
        return result;
    }

    // TC : O(M * N)
    // SC : O(M * N)
    vector<vector<int>> approach_2(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    int r1 = i;
                    int c1 = j;
                    int r2 = -1;
                    int c2 = -1;
                    bfs(land, i, j, r2, c2, m, n);
                    result.push_back({r1, c1, r2, c2});
                }
            }
        }
        return result;
    }

    // TC : O(M * N)
    // SC : O(1)
    vector<vector<int>> approach_3(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (land[i][j] == 0) continue;
                
                // finding rightmost col of current group
                int c1 = j;
                while(c1 < n && land[i][c1]) c1 ++;

                // finding bottom most row of current group
                int r1 = i;
                while(r1 < m && land[r1][j]) r1 ++;

                r1 = r1 == 0 ? r1 : r1 - 1;
                c1 = c1 == 0 ? c1 : c1 - 1;

                for (int k = i; k <= r1; k++) {
                    for (int l = j; l <= c1; l++) {
                        land[k][l] = 0;     // visited
                    }
                }

                result.push_back({i, j, r1, c1});
            }
        }
        return result;
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        // return approach_1(land);

        // return approach_2(land);

        return approach_3(land);
    }
};
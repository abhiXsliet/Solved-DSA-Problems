// https://www.geeksforgeeks.org/problems/rotten-oranges2536/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int n, m;
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // TC : O(N * M)
    // SC : O(N * M)
    int approach_1(vector<vector<int>> &mat) {
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (mat[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        int minTime = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size --) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for (auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && mat[i_][j_] == 1) {
                        q.push({i_, j_});
                        mat[i_][j_] = 2;
                    }
                }
            }
            minTime += 1;
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (mat[i][j] == 1)
                    return -1;
            }
        }
        return (minTime - 1 < 0) ? 0 : minTime - 1;
    }

    // TC : O(N * M)
    // SC : O(N * M)
    int approach_2(vector<vector<int>> &mat) {
        queue<pair<int, int>> q;
        int freshOranges = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (mat[i][j] == 2) {
                    q.push({i, j});
                } else if (mat[i][j] == 1) {
                    freshOranges += 1;   
                }
            }
        }
        
        if (freshOranges == 0) return 0;    // nothing to make rotten
        
        int minTime = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size --) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for (auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && mat[i_][j_] == 1) {
                        q.push({i_, j_});
                        mat[i_][j_] = 2;
                        freshOranges --;
                    }
                }
            }
            minTime += 1;
        }
        return freshOranges == 0 ? minTime - 1 : -1;
    }
  public:
    int orangesRot(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        return approach_1(mat); 
        // return approach_2(mat); // optimized extra loop
    }       
};
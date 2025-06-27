// https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    vector<vector<int>> directions {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    unordered_map<string, int> mpp;
    
    int dfs(int i, int j, int len, int n, vector<vector<int>> &mat) {
        if (len == n) return 1;
        string key = to_string(i) + "," + to_string(j) + "," + to_string(len);
        if (mpp.count(key)) return mpp[key];
        int ans = 0;
        for (auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (i_ < 4 && i_ >= 0 && j_ < 3 && j_ >= 0 && mat[i_][j_] != INT_MAX) {
                ans += dfs(i_, j_, len + 1, n, mat);
            }
        }
        return mpp[key] = ans;
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_1(int n) {
        vector<vector<int>> mat(4, vector<int>(3, INT_MAX));
        int count = 1;
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                mat[i][j] = count ++;
            }
        }
        mat[3][1] = 0;
        
        int ans = 0;
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 3; j ++) {
                if (mat[i][j] != INT_MAX) 
                    ans += dfs(i, j, 1, n, mat);
            }
        }
        return ans;
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_2(int n) {
        vector<vector<int>> mat(4, vector<int>(3, INT_MAX));
        int count = 1;
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                mat[i][j] = count ++;
            }
        }
        mat[3][1] = 0;
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(4, vector<int>(3, 0)));
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 3; j ++) {
                if (mat[i][j] != INT_MAX) { // skip '*' & '#' cell
                    dp[1][i][j] = 1;
                }
            }
        }
        
        for (int len = 1; len <= n; len ++) {
            for (int i = 0; i < 4; i ++) {
                for (int j = 0; j < 3; j ++) {
                    if (mat[i][j] != INT_MAX) {
                        int &curr = dp[len][i][j];
                        for (auto &dir : directions) {
                            int i_ = i + dir[0];
                            int j_ = j + dir[1];
                            if (i_ < 4 && i_ >= 0 && j_ < 3 && j_ >= 0 && mat[i_][j_] != INT_MAX) {
                                curr += dp[len - 1][i_][j_];
                            }
                        }
                    }
                }
            }   
        }
        int ans = 0;
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 3; j ++) {
                if (mat[i][j] != INT_MAX) {
                    ans += dp[n][i][j];
                }
            }
        }
        return ans;
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_3(int n) {
        vector<vector<int>> mat(4, vector<int>(3, INT_MAX));
        int count = 1;
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                mat[i][j] = count ++;
            }
        }
        mat[3][1] = 0;
        
        vector<vector<int>> prevRow(4, vector<int>(3, 0)), currRow(4, vector<int>(3, 0));
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 3; j ++) {
                if (mat[i][j] != INT_MAX) { // skip '*' & '#' cell
                    prevRow[i][j] = 1;
                }
            }
        }
        
        for (int len = 2; len <= n; len ++) {
            
            // Reset Current State
            for (int f = 0; f < 4; f ++) {
                fill(begin(currRow[f]), end(currRow[f]), 0);
            }
            
            for (int i = 0; i < 4; i ++) {
                for (int j = 0; j < 3; j ++) {
                    
                    if (mat[i][j] != INT_MAX) {
                        for (auto &dir : directions) {
                            int i_ = i + dir[0];
                            int j_ = j + dir[1];
                            if (i_ < 4 && i_ >= 0 && j_ < 3 && j_ >= 0 && mat[i_][j_] != INT_MAX) {
                                currRow[i][j] += prevRow[i_][j_];
                            }
                        }
                    }
                }
            }   
            
            prevRow = currRow;
        }
        
        int ans = 0;
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 3; j ++) {
                if (mat[i][j] != INT_MAX) {
                    ans += prevRow[i][j];
                }
            }
        }
        return ans;
    }
  public:
    int getCount(int n) {
        // return approach_1(n);   // top-down
        // return approach_2(n);   // bottom-up
        return approach_3(n);   // space-optimized
    }
};
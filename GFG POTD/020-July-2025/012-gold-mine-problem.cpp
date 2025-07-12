// https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    vector<vector<int>> directions{{-1, 1}, {0, 1}, {1, 1}};
    int m, n;
    
    bool isValid(int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    
    int dfsOptimized(vector<vector<int>> &mat, int i, int j) {
        if (mat[i][j] < 0) return -mat[i][j];  // already computed

        int gold = mat[i][j];
        int maxNext = 0;
    
        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (isValid(i_, j_)) {
                maxNext = max(maxNext, dfsOptimized(mat, i_, j_));
            }
        }
    
        mat[i][j] = -(gold + maxNext);  // store memoized value as negative
        return -mat[i][j];
    }
    
    int dfs(vector<vector<int>> &mat, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];
        
        int temp = mat[i][j];
        mat[i][j] = -1; // visited
        
        int ans = 0;
        for (auto &dir : directions) {
            int i_ = (i + dir[0]);
            int j_ = (j + dir[1]);
            if (isValid(i_, j_) && mat[i_][j_] != -1) {
                ans = max(ans, dfs(mat, i_, j_, dp));
            }
        }
        
        mat[i][j] = temp;
        return dp[i][j] = max(dp[i][j], ans + temp);
    }
    
    // TC : O(M * N)
    // SC : O(M * N)
    int approach_1(vector<vector<int>> &mat) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int ans = 0;
        for (int i = 0; i < m; i ++) {
            ans = max(ans, dfs(mat, i, 0, dp));
        }
        return ans;
    }
    
    // TC : O(M * N)
    // SC : O(1)
    int approach_2(vector<vector<int>> &mat) {
        int ans = 0;
        for (int i = 0; i < m; i ++) {
            ans = max(ans, dfsOptimized(mat, i, 0));
        }
        return ans;
    }
    
    // TC : O(M * N)
    // SC : O(1)
    int approach_3(vector<vector<int>> &mat) {
        int ans = 0;
        for (int j = n - 2; j >= 0; j --) { // cols
            for (int i = 0; i < m; i ++) {
                
                int upperRight = 0, right = 0, downRight = 0;
                
                if (i - 1 >= 0 && j + 1 < n) 
                    upperRight = mat[i - 1][j + 1];
                    
                if (j + 1 < n) 
                    right = mat[i][j + 1];
                    
                if (i + 1 < m && j + 1 < n)
                    downRight = mat[i + 1][j + 1];
                
                mat[i][j] += max({upperRight, right, downRight});
                
                ans = max(ans, mat[i][j]);
            }
        }
        return ans;
    }
  public:
    int maxGold(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        
        // return approach_1(mat);
        // return approach_2(mat);  // modified input for memoization
        return approach_3(mat);  // tabulation code
    }
};
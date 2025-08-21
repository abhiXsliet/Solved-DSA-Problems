// https://leetcode.com/problems/count-square-submatrices-with-all-ones/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;   
    
    int mem(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp) {
        if (i >= m || j >= n || !matrix[i][j]) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int right = 1 + mem(matrix, i, j + 1, dp);
        int down  = 1 + mem(matrix, i + 1, j, dp);
        int diag  = 1 + mem(matrix, i + 1, j + 1, dp);

        return dp[i][j] = min({right, down, diag});
    }

    // TC : O(n*m*len*len*len) ~= O(n*m*k^3) where k = min(n, m) which is equal to len
    // SC : O(1)
    int brute(vector<vector<int>> &matrix) {
        int cntSqSubMatrices = 0;

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j]) {
                    for (int len = 1; len <= m - i && len <= n - j; len ++) {
                        bool isOne = true;
                        for (int x = i; x < i + len; x ++) {
                            for (int y = j; y < j + len; y ++) {
                                if (matrix[x][y] != 1) {
                                    isOne = false;
                                    break;
                                }
                            }
                        }
                        if (isOne) cntSqSubMatrices += 1;
                        else break; // No need to check larger squares
                    }
                }
            }
        }

        return cntSqSubMatrices;
    }


    // TC : O(N * M)
    // SC : O(N * M)
    int way_1(vector<vector<int>> &matrix) {
        int cntSqSubMatrices = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j]) {
                    cntSqSubMatrices += mem(matrix, i, j, dp);
                }
            }
        }
        
        return cntSqSubMatrices;
    }

    // TC : O(N * M)
    // SC : O(N * M)
    int way_2(vector<vector<int>> &matrix) {
        int cntSqSubMatrices = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j];
                } else if (matrix[i][j]) {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }

                cntSqSubMatrices += dp[i][j];
            }
        }

        return cntSqSubMatrices;
    }

    // TC : O(N * M)
    // SC : O(1)
    int way_3(vector<vector<int>> &matrix) {
        int cntSqSubMatrices = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i > 0 && j > 0 && matrix[i][j]) {
                    matrix[i][j] += min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]});
                }
                cntSqSubMatrices += matrix[i][j];
            }
        }
        return cntSqSubMatrices;
    }

    int optimal(vector<vector<int>> &matrix) {
        // return way_1(matrix);
        // return way_2(matrix);
        return way_3(matrix);
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();

        // return brute(matrix);
        return optimal(matrix);
    }
};
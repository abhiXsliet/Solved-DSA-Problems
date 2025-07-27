// https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(M * N)
    // SC : O(1)
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        
        bool isFirstRow = 0, isFirstCol = 0;
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i == 0 && !mat[i][j]) {
                    isFirstRow = 1;
                } else if (j == 0 && !mat[i][j]) {
                    isFirstCol = 1;
                } else if (!mat[i][j]) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (i == 0 && isFirstRow || j == 0 && isFirstCol || !mat[i][0] || !mat[0][j]) {
                    mat[i][j] = 0;
                } 
            }
        }
    }
};
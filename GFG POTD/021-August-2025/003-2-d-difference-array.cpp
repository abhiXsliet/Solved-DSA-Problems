// https://www.geeksforgeeks.org/problems/2-d-difference-array/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(M * N)
    // SC : O(M * N)
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> diffMat(m + 1, vector<int>(n + 1, 0));
        
        for (vector<int> &vec : opr) {
            int val = vec[0];
            int r1  = vec[1], c1 = vec[2], r2 = vec[3], c2 = vec[4];
            
            diffMat[r1][c1]         += val;
            diffMat[r1][c2 + 1]     -= val;
            diffMat[r2 + 1][c1]     -= val;
            diffMat[r2 + 1][c2 + 1] += val;
        }
        
        // find the prefix sum First row-wise
        for (int i = 0; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                diffMat[i][j] += diffMat[i][j - 1];
            }
        }
        
        // find the prefix sum column wise
        for (int i = 1; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                diffMat[i][j] += diffMat[i - 1][j];
            }
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                mat[i][j] += diffMat[i][j];
            }
        }
        
        return mat;
    }
};
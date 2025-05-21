// https://leetcode.com/problems/set-matrix-zeroes/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(M * N)
    // SC : O(M * N)
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool isRowZero = 0, isColZero = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (!matrix[i][j]) {
                    if (i == 0 && j == 0) {
                        isRowZero = 1;
                        isColZero = 1;
                    } else if (i == 0) {
                        isRowZero = 1;  
                    } else if (j == 0) {
                        isColZero = 1;  
                    } else {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (i == 0 && isRowZero || j == 0 && isColZero || !matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                } 
            }
        }
    }
};
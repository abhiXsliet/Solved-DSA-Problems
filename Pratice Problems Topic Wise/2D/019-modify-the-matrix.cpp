// https://leetcode.com/problems/modify-the-matrix/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*M)
    // SC : O(N)
    vector<vector<int>> solve_1(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> maxVal(n, 0);

        for (int i = 0; i < n; i++) {
            int maxi = INT_MIN;
            for (int j = 0; j < m; j++) {
                maxi = max(maxi, matrix[j][i]);
            }
            maxVal[i] = maxi;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = maxVal[j];
                }
            }
        }

        return matrix;
    }

    // TC : max(O(N*M), O(M*M))
    // SC : O(1)
    vector<vector<int>> solve_2(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i = 0; i < m; i++) {
            int col = -1;
            int row = -1;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    row = i;
                    col = j;
                }
            }
            int maxi = INT_MIN;
            for (int r = 0; r < m; r++) {
                if (col != -1)
                    maxi = max(maxi, matrix[r][col]);
                
            }
            if (row != -1 && col != -1) {
                matrix[row][col] = maxi;
                i --;
            }
        }
        return matrix;
    }

    // TC : O(N*M)
    // SC : O(1)
    vector<vector<int>> solve_3(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < n; i++) {
            int maxi = INT_MIN;
            for (int j = 0; j < m; j++) {
                maxi = max(maxi, matrix[j][i]);
            }
            for (int j = 0; j < m; j++) {
                if (matrix[j][i] == -1) {
                    matrix[j][i] = maxi;
                }
            }
        }
        return matrix;
    }
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        // return solve_1(matrix);

        // return solve_2(matrix);

        return solve_3(matrix);
    }
};
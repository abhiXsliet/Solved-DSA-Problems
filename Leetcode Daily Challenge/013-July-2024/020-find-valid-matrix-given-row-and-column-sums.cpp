// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(M + N) Where M = No. of Rows and N = No. of Columns
    // SC : O(1) auxiliary space
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> mat(m, vector<int>(n, 0));

        int i = 0, j = 0;
        while (i < m && j < n) {
            mat[i][j]  = min(rowSum[i], colSum[j]);
            
            rowSum[i] -= mat[i][j];
            colSum[j] -= mat[i][j];

            if (rowSum[i] == 0) i ++;
            if (colSum[j] == 0) j ++;
        }
        return mat;
    }
};
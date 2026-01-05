// https://leetcode.com/problems/maximum-matrix-sum/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        long long result = 0;
        int cntNegatives = 0;
        int minNumber = INT_MAX;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] < 0) {
                    cntNegatives ++;
                }
                result   += abs(matrix[i][j]);
                minNumber = min(minNumber, abs(matrix[i][j]));
            }
        }
        if (cntNegatives % 2) {
            result -= 2*minNumber;
        }
        return result;
    }
};
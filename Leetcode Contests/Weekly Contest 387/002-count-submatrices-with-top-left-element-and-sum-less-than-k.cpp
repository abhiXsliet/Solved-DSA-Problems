// https://leetcode.com/contest/weekly-contest-387/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(N^2)
    vector<vector<int>> computePrefixSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> prefixSum(rows, vector<int>(cols));

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                prefixSum[i][j] = matrix[i][j] 
                                + (i > 0 ? prefixSum[i - 1][j] : 0) 
                                + (j > 0 ? prefixSum[i][j - 1] : 0) 
                                - (i > 0 && j > 0 ? prefixSum[i - 1][j - 1] : 0);
            }
        }

        return prefixSum;
    }
    
public:
    // TC : O(N^2)
    // SC : O(N^2)
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        auto prefixSum = computePrefixSum(grid);
        
        int rows = prefixSum.size();
        int cols = prefixSum[0].size();
        int count = 0;

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (prefixSum[i][j] <= k) {
                    count ++;
                }
            }
        }

        return count;
    }
};
// https://www.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(M * M)
    // SC : O(1)
    int balanceSums(vector<vector<int>>& mat) {
        int m = mat.size();
        int maxSum = 0;
        for (int i = 0; i < m; i ++) {
            int sum1 = 0, sum2 = 0;
            for (int j = 0; j < m; j ++) {
                sum1 += mat[j][i];
                sum2 += mat[i][j];
            }
            maxSum = max({maxSum, sum1, sum2});
        }

        int minOpr = 0;
        for (int i = 0; i < m; i ++) {
            int sum = 0;
            for (int j = 0; j < m; j ++) {
                sum += mat[j][i];
            }
            minOpr += abs(maxSum - sum);
        }
        return minOpr;
    }
};
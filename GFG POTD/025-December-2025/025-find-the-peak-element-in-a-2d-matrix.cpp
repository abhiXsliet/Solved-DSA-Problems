// https://www.geeksforgeeks.org/problems/find-the-peak-element-in-a-2d-matrix/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int getRowForMaxInCol(vector<vector<int>>& mat, int col, int n) {
        int maxi = INT_MIN;
        int rowIdx = -1;   // for max in col, index of resp. row
        for (int i = 0; i < n; i ++) {
            if (mat[i][col] > maxi) {
                maxi = mat[i][col];
                rowIdx = i;
            }
        }
        return rowIdx;
    }
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            int rowIdx = getRowForMaxInCol(mat, mid, n);
            
            int left  = (mid - 1 >= 0) ? mat[rowIdx][mid - 1] : INT_MIN;
            int right = (mid + 1 <  m) ? mat[rowIdx][mid + 1] : INT_MIN;
            
            if (mat[rowIdx][mid] >= left && mat[rowIdx][mid] >= right) {
                return {rowIdx, mid};
            } else if (mat[rowIdx][mid] > left) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return {-1, -1};
    }
};
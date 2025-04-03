// https://leetcode.com/problems/find-a-peak-element-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M)
    // SC : O(1)
    // This fn. returns the maxEle from the mid col. of mat 
    int getMaxRowIdx(vector<vector<int>> &mat, int mid, int m) {
        int maxRowI = 0, maxEle = mat[0][mid];
        for (int i = 0; i < m; i ++) {
            if (mat[i][mid] > maxEle) {
                maxEle = mat[i][mid];
                maxRowI = i;
            }
        }
        return maxRowI;
    }
public:
    // TC : O(N * log(M))
    // SC : O(1)
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int maxRowIdx = getMaxRowIdx(mat, mid, m);
            int leftEle   = (mid - 1 >= 0) ? mat[maxRowIdx][mid - 1] : -1;
            int rightEle  = (mid + 1 <  n) ? mat[maxRowIdx][mid + 1] : -1;

            if (mat[maxRowIdx][mid] > leftEle && mat[maxRowIdx][mid] > rightEle) {
                return {maxRowIdx, mid};

            } else if (mat[maxRowIdx][mid - 1] > mat[maxRowIdx][mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};
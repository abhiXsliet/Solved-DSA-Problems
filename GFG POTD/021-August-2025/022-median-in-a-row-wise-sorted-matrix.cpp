// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int getMedianPos(vector<vector<int>> &mat, int tar) {
        int cntPos = 0;
        for (int i = 0; i < mat.size(); i ++) {
            cntPos += upper_bound(begin(mat[i]), end(mat[i]), tar) - begin(mat[i]);
        }
        return cntPos;
    }
  public:
    // TC : O(log(maxi - mini) * nlogm)
    // SC : O(1)
    int median(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        int low = INT_MAX, high = INT_MIN;
        int medianPos = ((n * m) / 2) + 1;
        
        for (int i = 0; i < n; i ++) {
            low  = min(low , mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }
        
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int pos = getMedianPos(mat, mid);
            if (pos < medianPos) {    // median is higher than mid
                low = mid + 1;
            } else {
                result = mid;   // can be a potential median
                high = mid - 1;
            }
        }
        return result;
    }
};
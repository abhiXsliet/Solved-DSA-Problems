// https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // returns the cnt of no. less than or equal to tar
    int cntLessThanK(vector<vector<int>> &matrix, int tar) {
        int n = matrix.size();
        int cnt = 0;    
        for (int i = 0; i < n; i ++) {
            cnt += upper_bound(begin(matrix[i]), end(matrix[i]), tar) - begin(matrix[i]);
        }
        return cnt;
    }
  public:
    // TC : O(log(R) * N*log(N))
    // SC : O(1)
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int low  = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (cntLessThanK(matrix, mid) >= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
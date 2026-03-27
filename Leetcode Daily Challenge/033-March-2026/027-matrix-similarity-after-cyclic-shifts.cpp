// https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    // TC : O(M * N)
    // SC : O(M * N)
    bool approach_1(vector<vector<int>> &mat, int k) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> grid = mat;
        
        k = k % n;
        if (k == 0) return true;

        for (int i = 0; i < m; i ++) {
            if (i % 2) {
                rotate(rbegin(mat[i]), rbegin(mat[i]) + k, rend(mat[i]));
            } else {
                rotate(begin(mat[i]), begin(mat[i]) + k, end(mat[i]));
            }
        }

        return grid == mat;
    }

    // TC : O(M * N)
    // SC : O(1)
    bool approach_2(vector<vector<int>> &mat, int k) {
        int m = mat.size(), n = mat[0].size();
        
        k = k % n;
        if (k == 0) return true;

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int currIdx = j;
                int finalIdx;

                if (i % 2) {    // odd : right shift
                    finalIdx = (j - k + n) % n;
                } else {
                    finalIdx = (j + k) % n;
                }

                if (mat[i][currIdx] != mat[i][finalIdx])
                    return false;
            }
        }

        return true;
    }
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        // return approach_1(mat, k);
        return approach_2(mat, k);
    }
};
// https://leetcode.com/problems/count-submatrices-with-all-ones/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getSubMatricesCnt1D(vector<int> &arr) {
        int countSubMat = 0, consec = 0;
        for (int &val : arr) {
            if (!val) consec = 0;
            else consec += 1;
            countSubMat += consec;
        }
        return countSubMat;
    }

    // TC : O(M * M * N)
    // SC : O(N)
    int approach_1(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        int cntSubMatrices = 0;

        for (int stRow = 0; stRow < m; stRow ++) {

            vector<int> compressed(n, 1);
            for (int enRow = stRow; enRow < m; enRow ++) {
                for (int j = 0; j < n; j ++) {
                    compressed[j] &= mat[enRow][j];
                }
                cntSubMatrices += getSubMatricesCnt1D(compressed);
            }
        }
        
        return cntSubMatrices;
    }
public:
    int numSubmat(vector<vector<int>>& mat) {
        return approach_1(mat);
    }
};
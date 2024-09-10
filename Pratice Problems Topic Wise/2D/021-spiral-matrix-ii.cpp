// https://leetcode.com/problems/spiral-matrix-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*N)
    // SC : O(1)
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));

        int stRow = 0;
        int stCol = 0;
        int enRow = n - 1;
        int enCol = n - 1;
        int val = 1;

        while (stRow <= enRow && stCol <= enCol) {
            for (int j = stCol; j <= enCol; j ++) {
                result[stRow][j] = val ++;
            }
            stRow ++;
            for (int i = stRow; i <= enRow; i ++) {
                result[i][enCol] = val ++;
            }
            enCol --;
            for (int j = enCol; j >= stCol; j --) {
                result[enRow][j] = val ++;
            }
            enRow --;
            for (int i = enRow; i >= stRow; i --) {
                result[i][stCol] = val ++;
            }
            stCol ++;
        }

        return result;
    }
};
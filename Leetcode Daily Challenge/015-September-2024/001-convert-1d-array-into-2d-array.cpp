// https://leetcode.com/problems/convert-1d-array-into-2d-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M * N)
    // SC : O(1)
    vector<vector<int>> approach_1(vector<int>& original, int m, int n) {
        int size = original.size();
        if (m * n < size || size < m * n) 
            return {};

        vector<vector<int>> result(m, vector<int>(n, 0));

        int row = 0;
        int idx = 1;
        
        for (int i = 0; i < size; i += n) {
            for (int j = i; j <=  (idx * n) - 1; j ++) {
                result[row][j % n] = original[j];
            }
            idx ++;
            row ++;
        }
        
        return result;
    }

    // TC : O(M * N)
    // SC : O(1)
    vector<vector<int>> approach_2(vector<int>& original, int m, int n) {
        int size = original.size();
        
        if (m * n != size) return {};

        vector<vector<int>> result(m, vector<int>(n, 0));

        int idx = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                result[i][j] = original[idx ++];
            }
        }
        return result;
    }

    // TC : O(M * N)
    // SC : O(1)
    vector<vector<int>> approach_3(vector<int>& original, int m, int n) {
        int size = original.size();

        if (m * n != size) return {};

        vector<vector<int>> result(m, vector<int>(n, 0));

        for (int i = 0; i < size; i ++) {
            result[i / n][i % n] = original[i];
        }
        return result;
    }
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // return approach_1(original, m, n);

        // return approach_2(original, m, n);      // same as approach_1

        return approach_3(original, m, n);  // i/n -> row; i%n -> col
    }
};
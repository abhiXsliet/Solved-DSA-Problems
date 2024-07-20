// https://leetcode.com/problems/lucky-numbers-in-a-matrix/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M * N)
    // SC : O(M + N)
    vector<int> approach_1(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        vector<int> rowMin;
        vector<int> colMax;

        for (int i = 0; i < m; i ++) {
            int minVal = INT_MAX;
            for (int j = 0; j < n; j ++) {
                minVal = min(minVal, mat[i][j]);
            }
            rowMin.push_back(minVal);
        }

        for (int j = 0; j < n; j ++) {
            int maxVal = INT_MIN;
            for (int i = 0; i < m; i ++) {
                maxVal = max(maxVal, mat[i][j]);
            }
            colMax.push_back(maxVal);
        }

        vector<int> result;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == rowMin[i] && mat[i][j] == colMax[j]) {
                    result.push_back(mat[i][j]);
                }
            }
        }
        return result;
    }

    // TC : O(M * N)
    // SC : O(1)
    vector<int> approach_2(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        int rowMinMax = INT_MIN;  // Min value of its row and max val of its column
        int colMaxMin = INT_MAX;  // Max value of its col and min val of its row

        for (int i = 0; i < m; i ++) {
            int minVal = INT_MAX;
            for (int j = 0; j < n; j ++) {
                minVal = min(minVal, mat[i][j]);
            }
            rowMinMax = max(rowMinMax, minVal);
        }

        for (int j = 0; j < n; j ++) {
            int maxVal = INT_MIN;
            for (int i = 0; i < m; i ++) {
                maxVal = max(maxVal, mat[i][j]);
            }
            colMaxMin = min(colMaxMin, maxVal);
        }

        if(rowMinMax == colMaxMin)
            return {rowMinMax};
            
        return {};
    }
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // return approach_1(matrix);


        return approach_2(matrix);
    }
};
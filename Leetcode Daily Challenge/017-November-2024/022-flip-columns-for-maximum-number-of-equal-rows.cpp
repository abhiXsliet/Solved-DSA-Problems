// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M * (N + M * M)) ~= O(M^2 * N)
    // SC : O(N)
    int approach_1(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for (auto& currRow : matrix) {
            vector<int> inverted(n);
            
            for (int j = 0; j < n; j ++) {
                inverted[j] = currRow[j] == 0 ? 1 : 0;  // flip : 1 - currRow[j]
            }

            int count = 0;
            for (auto& row : matrix) {
                if (row == currRow || row == inverted) {
                    count ++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int approach_2(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<string, int> mpp;

        for (auto& row : matrix) {
            string pattern;

            int firstVal = row[0];
            for (int j = 0; j < n; j ++) {
                pattern += (firstVal == row[j]) ? "S" : "B";
            }

            mpp[pattern] ++;
        }

        int result = 0;
        for (auto& it : mpp) {
            result = max(result, it.second);
        }
        return result;
    }
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // return approach_1(matrix);  

        return approach_2(matrix);
    }
};
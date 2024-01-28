// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : (rows^3 * cols^3)
    // SC : O(1)
    int solve_brute(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans  = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                for (int i = r; i < rows; i++) {
                    for (int j = c; j < cols; j++) {
                        
                        int sum = 0;
                        for (int row = r; row <= i; row++) {
                            for (int col = c; col <= j; col++) {

                                sum += matrix[row][col];
                            }
                        }

                        if (sum == target) {
                            ans += 1;
                        }
                    }
                }
            }
        }
        return ans;
    }

    // TC : O(rows * cols^2)
    // SC : O(rows)
    int solve_optimal(vector<vector<int>>& mat, int tar) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Taking row wise cummulative sum 
        for (int r = 0; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                mat[r][c] += mat[r][c - 1];
            }
        }

        int ans = 0;

        // Now find the no. of subarrays with sum == target (leetcode-560) => Downward direction
        for (int startCol = 0; startCol < cols; startCol++) {
            
            for (int c = startCol; c < cols; c++) {

                unordered_map<int, int> mpp; // {cumm_sum, times_cumm_sum}
                
                int cumm_sum = 0;
                mpp.insert({cumm_sum, 1});

                for (int row = 0; row < rows; row++) {

                    cumm_sum += mat[row][c] - (startCol > 0 ? mat[row][startCol - 1] : 0);

                    if(mpp.find(cumm_sum - tar) != mpp.end()) {
                        
                        ans += mpp[cumm_sum - tar];
                    }

                    mpp[cumm_sum] ++;
                }
            }
        }
        return ans;
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // return solve_brute(matrix, target);

        return solve_optimal(matrix, target);
    }
};
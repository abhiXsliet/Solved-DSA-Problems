// https://www.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // Kadane's algorithm: finds the maximum subarray sum in 1D array
    int kadanes(vector<int> &arr) {
        int maxSum = INT_MIN, prev = 0;
        for (int &num : arr) {
            // Either extend the previous subarray or start new from current
            prev   = max(num, num + prev);
            maxSum = max(maxSum, prev);
        }
        return maxSum;
    }
    
    // TC : O(M^3 * N^3)
    // SC : O(1)
    int brute(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        int maxSubMatSum = INT_MIN;

        // (i, j) is top-left corner of submatrix
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                
                // (k, l) is bottom-right corner of submatrix
                for (int k = i; k < m; k ++) {
                    for (int l = j; l < n; l ++) {
                        
                        int subMatSum = 0;
                        
                        // Now sum over the submatrix (i,j) to (k,l)
                        for (int x = i; x <= k; x ++) {
                            for (int y = j; y <= l; y ++) {
                                subMatSum += mat[x][y];
                            }
                        }
                        
                        maxSubMatSum = max(maxSubMatSum, subMatSum);
                    }
                }
            }
        }
        
        return maxSubMatSum;
    }
    
    // TC : O(M^2 * N^2)
    // SC : O(M * N)
    int better (vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        
        // prefix[i][j] = sum of all elements from (0,0) to (i,j)
        vector<vector<int>> prefix(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                
                prefix[i][j] = mat[i][j];
                if (i - 1 >= 0) prefix[i][j] += prefix[i - 1][j];  
                if (j - 1 >= 0) prefix[i][j] += prefix[i][j - 1];
                if (i - 1 >= 0 && j - 1 >= 0) prefix[i][j] -= prefix[i - 1][j - 1];    // to remove double counted overlap
            } 
        }
        
        int maxSubMatSum = INT_MIN;
        
        for (int i1 = 0; i1 < m; i1 ++) {
            for (int j1 = 0; j1 < n; j1 ++) {
                
                for (int i2 = i1; i2 < m; i2 ++) {
                    for (int j2 = j1; j2 < n; j2 ++) {
                        
                        int subMatSum = prefix[i2][j2];
                        
                        if (i1 - 1 >= 0) subMatSum -= prefix[i1 - 1][j2];
                        if (j1 - 1 >= 0) subMatSum -= prefix[i2][j1 - 1];
                        if (i1 - 1 >= 0 && j1 - 1 >= 0) subMatSum += prefix[i1 - 1][j1 - 1];    // (add back top-left overlap)
                        
                        maxSubMatSum = max(maxSubMatSum, subMatSum);
                    }
                }
            }
        }
        
        return maxSubMatSum;
    }
    
    // TC : O(M * N^2) Where M = No. of Rows and N = No. of cols
    // SC : O(M)
    int optimal(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        
        int maxSubMatSum = INT_MIN;
        
        // Step 1: Fix the left column of the submatrix
        for (int left = 0; left < n; left ++) { 
            
            // stores row-wise sum between columns [left...right]
            vector<int> temp(m);
            
            // Step 2: Move the right column from left to end
            for (int right = left; right < n; right ++) {
                
                // Step 3: Compress the 2D matrix into 1D row sums for current column window
                for (int i = 0; i < m; i ++) {
                    temp[i] += mat[i][right];
                }
                
                // Step 4: Apply Kadane's on the compressed array to get max subarray sum & update the maxSubMatSum
                maxSubMatSum = max(maxSubMatSum, kadanes(temp));
            }
        }
        
        return maxSubMatSum;
    }
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        // return brute(mat);      // TLE : TC : O(M^3 * N^3) + SC : O(1)
        // return better(mat);     // TLE : TC : O(M^2 * N^2) + SC : O(N*M) => using prefixSum
        return optimal(mat);
    }
};
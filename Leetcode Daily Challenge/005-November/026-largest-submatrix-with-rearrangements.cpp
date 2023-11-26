// https://leetcode.com/problems/largest-submatrix-with-rearrangements/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(M*N*log(N))
    // SC = O(MN)
    int solve_approach_1(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxArea = 0;

        // O(M)
        for (int row = 0; row < m; row++) {

            for (int col = 0; col < n; col++) {

                if (matrix[row][col] == 1 && row > 0) {
                    matrix[row][col] += matrix[row - 1][col];
                }
            }

            vector<int> heights = matrix[row];
            
            // O(N * log(N))
            sort(begin(heights), end(heights), greater<int>());

            for (int i = 0; i < heights.size(); i++) {
                int base   = (i + 1); // since prev value can be equal or greater

                int height = heights[i];

                maxArea    = max(maxArea, (base * height));
            }
        }

        return maxArea;
    }

    // TC = O(MN * log(N))
    // SC = O(MN)
    int solve_approach_2(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxArea = 0;

        vector<int> prevRow(n, 0);

        // O(M)
        for (int row = 0; row < m; row++) {

            vector<int> currRow = matrix[row];

            for (int col = 0; col < n; col++) {

                if (currRow[col] == 1) {
                    currRow[col] += prevRow[col];
                }
            }

            vector<int> heights = currRow;
            
            // O(N * log(N))
            sort(begin(heights), end(heights), greater<int>());

            for (int i = 0; i < heights.size(); i++) {
                int base   = (i + 1); // since prev value can be equal or greater

                int height = heights[i];

                maxArea    = max(maxArea, (base * height));
            }

            prevRow = currRow;
        }

        return maxArea;
    }

    // TC = O(MN)
    // SC = O(MN)
    int solve_approach_3(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxArea = 0;

        vector<pair<int, int>> prevHeights; // {height, col}

        for (int row = 0; row < m; row++) {

            vector<pair<int, int>> currHeights;
            vector<bool> seen(n, false);

            for (auto [height, col] : prevHeights) {

                if (matrix[row][col] == 1) {

                    currHeights.push_back({height + 1, col});
                    seen[col] = true;
                }
            }

            for (int col = 0; col < n; col++) {

                if (matrix[row][col] == 1 && seen[col] == false) {
                    
                    currHeights.push_back({1, col});
                }
            }

            for (int i = 0; i < currHeights.size(); i++) {

                int height = currHeights[i].first;
                int base   = i + 1;

                maxArea    = max(maxArea, height * base);
            }

            prevHeights = currHeights;
        }
        
        return maxArea;
    }

public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        // return solve_approach_1(matrix);

        // return solve_approach_2(matrix);

        return solve_approach_3(matrix);
    }
};
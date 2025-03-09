// https://leetcode.com/problems/find-missing-and-repeated-values/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(N^2)
    // SC : O(N^2)
    vector<int> approach_1(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<int> store(n*n + 1, 0);
        int duplicate = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                int idx = grid[i][j];
                if (!store[idx]) 
                    store[idx] = grid[i][j];
                else 
                    duplicate = grid[i][j];
            }
        }

        int missing = 0;
        for (int i = 1; i <= store.size(); i ++) {
            if (!store[i]) {
                missing = i;
                break;
            }
        }
        return {duplicate, missing};
    }

/*
    1. Interpret the 2D grid as a flattened 1D array, marking elements as negative to track duplicates.  
        - If an element at an index is already negative, it indicates index is a duplicate element.
        - This follows a similar approach used for detecting duplicates in a 1D array.  
    2. Perform a second traversal to locate the first non-negative element.  
        - The index of this element corresponds to the missing value, as no extra element was available to mark it as negative.
*/
    // TC : O(N^2)
    // SC : O(1)
    vector<int> approach_2(vector<vector<int>> &grid) {
        int n = grid.size();
        // mark negative to detect duplicate, if already marked then store it as duplicate
        int duplicate = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                int ele = abs(grid[i][j]) - 1;   // converting for 0-based indexing
                int r = ele / n;
                int c = ele % n;
                if (grid[r][c] < 0) {
                    duplicate = abs(grid[i][j]);
                }else {
                    grid[r][c] = grid[r][c] * (-1); 
                }
            }
        }   

        // traverse again on grid to get the first non-negative element, since no one marks it : means nothing but a missing element
        int missing = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] > 0) {
                    cout << grid[i][j] << endl;
                    missing = ((i * n) + (j + 1));
                    break;
                }
            }
        }
        return {duplicate, missing};
    }
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // return approach_1(grid);     // n*n array map it with elements
        return approach_2(grid);     // Treat 2D grid as a continuous 1D array & mark -ve treating element as indices 
    }
};
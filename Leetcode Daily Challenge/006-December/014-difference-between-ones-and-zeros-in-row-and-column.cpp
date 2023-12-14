// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/



#include <bits/stdc++.h>
using namespace std; 

class Solution {
private:
    // TC = O(M*N + (M+N))  -> TLE
    // SC = O(M*N) -> to return the ans 
    vector<vector<int>> solve_brute(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> diff(m, vector<int>(n, 0));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                int rowOnes = 0, colOnes = 0, colZeros = 0, rowZeros = 0;

                //check ones/zeros in rows
                for (int r = 0; r < m; r++) {
                    if (grid[r][col] == 1) rowOnes++;
                    else rowZeros++;
                }
                // check ones/zeros in cols
                for (int c = 0; c < n; c++) {
                    if (grid[row][c] == 1) colOnes++;
                    else colZeros++;
                }
                
                diff[row][col] = rowOnes + colOnes - rowZeros - colZeros;
            }
        }
        return diff;
    }

    // TC = O(M*N)
    // SC = O(M+N) 
    vector<vector<int>> solve_optimal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> storeRowOnes(m, 0);
        vector<int> storeColOnes(n, 0);

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    storeRowOnes[row]++;
                    storeColOnes[col]++;
                }
            }
        }

        vector<vector<int>> diff(m, vector<int>(n, 0));
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                int rowOnes = storeRowOnes[row];
                int colOnes = storeColOnes[col];
                int colZeros = m - colOnes; // rows - colsOnes
                int rowZeros = n - rowOnes; // cols - rowOnes
                
                diff[row][col] = rowOnes + colOnes - rowZeros - colZeros;
            }
        }
        return diff;
    }
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        // return solve_brute(grid);

        return solve_optimal(grid);
    }
};
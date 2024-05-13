// https://leetcode.com/problems/score-after-flipping-matrix/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:    
    // TC : O(M * N)
    // SC : O(1)
    int approach_1(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                // flip row
                for (int j = 0; j < n; j++) {
                    grid[i][j] = 1 - grid[i][j];    // flipping
                }
            }
        }

        for (int j = 1; j < n; j++) {
            int cntZeros = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 0) {
                    cntZeros ++;
                }
            }

            int cntOnes = m - cntZeros;
            if (cntZeros > cntOnes) {
                // flipping the cols
                for (int i = 0; i < m; i++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        int score = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                int val = grid[i][j] * pow(2, n - j - 1);   // grid[i][j] << (n - j - 1)
                score  += val;
            }
        }
        return score;
    }

    // TC : O(M * N)
    // SC : O(1)
    int approach_2(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int score = pow(2, n - 1) * m;  // store values of all MSB (2^n - 1)

        for (int j = 1; j < n;  j ++) {

            int cntSameBits = 0;    // count ones == cntSameBits
            for (int i = 0; i < m; i ++) {
                if (grid[i][j] == grid[i][0]) {
                    cntSameBits ++;
                }
            }

            int cntOnes  = cntSameBits;
            int cntZeros = m - cntOnes;

            int ones     = max(cntOnes, cntZeros);

            score       += (pow(2, n - j - 1) * ones);
        }
        return score;
    }
public:
    int matrixScore(vector<vector<int>>& grid) {
        // return approach_1(grid);

        return approach_2(grid);    // without modifying 2-D array
    }
};
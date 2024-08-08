// https://leetcode.com/problems/spiral-matrix-iii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O( [max(rows, cols)] ^ 2 ) 
    // SC : O( 1 )
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // {E, S, W, N}

        vector<vector<int>> result;
        result.push_back({rStart, cStart});
        int dir   = 0;    // E
        int steps = 0;

        while (result.size() < rows * cols) {
            if (dir == 0 || dir == 2)  // E or W
                steps ++;
            
            for (int count = 0; count < steps; count ++) {
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) 
                    result.push_back({rStart, cStart});
            }
            dir = (dir + 1) % 4;
        }
        return result;
    }
};
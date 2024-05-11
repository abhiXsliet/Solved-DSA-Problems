// https://leetcode.com/contest/biweekly-contest-129/problems/make-a-square-with-the-same-color/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int n = grid.size();
        
        for (int i = 0; i < n - 1; i ++) {
            for (int j = 0; j < n - 1; j ++) {
                
                int blackCount = 0;
                blackCount += (grid[i][j] == 'B');
                blackCount += (grid[i][j+1] == 'B');
                blackCount += (grid[i+1][j] == 'B');
                blackCount += (grid[i+1][j+1] == 'B');

                if (blackCount == 3 || blackCount == 4 || blackCount == 0 || blackCount == 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
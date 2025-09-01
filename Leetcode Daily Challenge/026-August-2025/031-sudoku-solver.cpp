// https://leetcode.com/problems/sudoku-solver/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:    
    bool isValid(vector<vector<char>> &board, int i, int j, char d) {
        for (int k = 0; k < 9; k ++) {
            if (board[i][k] == d) return false; // found same digit in row
            if (board[k][j] == d) return false; // found same digit in col

            // 3x3 box check for duplicate digits
            int boxR = (i / 3 * 3) + k / 3;
            int boxC = (j / 3 * 3) + k % 3;
            if (board[boxR][boxC] == d) return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') {
                    for (char d = '1'; d <= '9'; d ++) {
                        if (isValid(board, i, j, d)) {
                            board[i][j] = d;
                            if (solve(board))
                                return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;   // no valid digit worked
                }
            }
        }
        return true;
    }
public:
    // TC : O(9^(N*N))
    // SC : O(1)
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
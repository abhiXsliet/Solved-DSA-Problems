// https://leetcode.com/problems/game-of-life/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * M) Where N = No. of Rows & M = No. of Cols
    // SC : O(N * M) 
    void solve_approach_1(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<int>> ansBoard = board;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                
                int sum = 0;
                for (int u = -1; u <= 1; u++) {
                    for (int v = -1; v <= 1; v++) {
                        
                        if (u == 0 && v == 0)
                            continue;
                            
                        int n_i = i + u;
                        int n_j = j + v;

                        if (n_i >= 0 && n_i < row && n_j >= 0 && n_j < col) {
                            sum += board[n_i][n_j];
                        }
                    }
                }

                if (sum == 0 || sum > 3 || sum < 2) ansBoard[i][j] = 0;
                else if (sum == 2) ansBoard[i][j] = board[i][j];
                else if (sum == 3) ansBoard[i][j] = 1;
            }
        }
        
        board = ansBoard;
    }

    // TC : O(N * M) Where N = No. of Rows & M = No. of Cols
    // SC : O(1) 
    void solve_approach_2(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                
                int sum = 0;
                for (int u = -1; u <= 1; u++) {
                    for (int v = -1; v <= 1; v++) {
                        if (u == 0 && v == 0) 
                            continue;

                        int n_i = i + u;
                        int n_j = j + v;

                        if (n_i >= 0 && n_i < row && n_j >= 0 && n_j < col && 
                            (board[n_i][n_j] == 1 || board[n_i][n_j] == 2) ) {
                            sum++; 
                        }
                    }
                }
                // board[i][j] = 1 -> Represents a live cell that will stay alive
                // board[i][j] = 2 -> Represents that a live cell will die
                if (board[i][j] == 1 && (sum < 2 || sum > 3)) // die
                    board[i][j] = 2;
                else if (board[i][j] == 0 && sum == 3)  // reproduce
                    board[i][j] = 3;
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                board[i][j] %= 2;
            }
        }        
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        // solve_approach_1(board);

        solve_approach_2(board);
    }
};
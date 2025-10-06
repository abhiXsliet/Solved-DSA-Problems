// https://www.geeksforgeeks.org/problems/the-knights-tour-problem/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    vector<int> dx = {2, 2, -2, -2, 1, -1, 1, -1};
    vector<int> dy = {1, -1, 1, -1, 2, 2, -2, -2};

    bool isValid(int x, int y, int n, vector<vector<int>> &board) {
        return x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1;
    }

    bool solve(int x, int y, int move, int n, vector<vector<int>> &board) {
        if (move == n * n) return true; // all squares visited 

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny, n, board)) {
                board[nx][ny] = move; // mark step number
                if (solve(nx, ny, move + 1, n, board))
                    return true;
                board[nx][ny] = -1; // backtrack
            }
        }
        return false;
    }

  public:
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> board(n, vector<int>(n, -1));
        board[0][0] = 0; // start from (0,0)

        if (solve(0, 0, 1, n, board))
            return board; // solution mil gaya
        else
            return {}; // no solution possible
    }
};
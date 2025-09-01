// https://leetcode.com/problems/sudoku-solver/




class Solution {
    public void solveSudoku(char[][] board) {
        solve(board);
    }
    
    // TC : O(9^(N*N))
    // SC : O(1)
    private boolean solve(char[][] board) {
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') {
                    for (char d = '1'; d <= '9'; d ++) {
                        if (isValid(board, i, j, d)) {
                            board[i][j] = d;
                            if (solve(board)) return true;
                            board[i][j] = '.';
                        } 
                    }
                    return false;   // no digit worked
                }
            }
        }
        return true;
    }

    private boolean isValid(char[][] board, int r, int c, char d) {
        for (int k = 0; k < 9; k ++) {
            if (board[r][k] == d) return false;
            if (board[k][c] == d) return false;

            // check in 3x3 box
            int boxRow = ((r / 3) * 3) + (k / 3);
            int boxCol = ((c / 3) * 3) + (k % 3);

            if (board[boxRow][boxCol] == d) return false;
        }
        return true;
    }
}
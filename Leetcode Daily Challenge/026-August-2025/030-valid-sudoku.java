// https://leetcode.com/problems/valid-sudoku/




import java.util.*;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        // return approach_1(board);
        // return approach_2(board);
        return approach_3(board);
    }

    // TC : O(1)
    // SC : O(1)
    private boolean approach_3(char[][] board) {
        int[] row = new int[9];
        int[] col = new int[9];
        int[] box = new int[9];

        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') continue;

                int val    = (board[i][j] - '1'); // 0-based indexing[0...8]
                int mask   = (1 << val);
                int boxIdx = (((i / 3) * 3) + (j / 3));

                if ( ((row[i] & mask) != 0) || ((col[j] & mask) != 0) || ((box[boxIdx] & mask) != 0) ) 
                    return false;

                row[i]      |= mask;
                col[j]      |= mask;
                box[boxIdx] |= mask;
            }
        }

        return true;
    }

    // TC : O(1)
    // SC : O(1)
    private boolean approach_2(char[][] board) {
        Set<String> st = new HashSet<>();
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') continue;

                String row = board[i][j] + "ROW" + i;
                String col = board[i][j] + "COL" + j;
                String box = board[i][j] + "BOX" + (i / 3) + "_" + (j / 3);

                if (st.contains(row) || st.contains(col) || st.contains(box))
                    return false;

                st.add(row);
                st.add(col);
                st.add(box);
            }
        }
        return true;
    }

    // TC : O(1)
    // SC : O(1)
    private boolean approach_1(char[][] board) {
        for (int i = 0; i < 9; i ++) {
            Set<Integer> st = new HashSet<>();
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') continue;

                int val = board[i][j] - '0';
                if (st.contains(val)) return false;
                else st.add(val);
            }

            st.clear();

            for (int j = 0; j < 9; j ++) {
                if (board[j][i] == '.') continue;

                int val = board[j][i] - '0';
                if (st.contains(val)) return false;
                else st.add(val);
            }
        }

        // check in 3x3 sub-matrix
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {

                Set<Integer> st = new HashSet<>();
                for (int k = i; k < i + 3; k ++) {
                    for (int l = j; l < j + 3; l ++) {
                        if (board[k][l] == '.') continue;

                        int val = board[k][l] - '0';
                        if (st.contains(val)) return false;
                        else st.add(val);
                    }
                }
            }
        }

        return true;
    }
}
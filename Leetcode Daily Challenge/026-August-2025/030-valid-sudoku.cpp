// https://leetcode.com/problems/valid-sudoku/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(1)
    // SC : O(1)
    bool approach_1(vector<vector<char>> &board) {
        int n = board.size();
        for (int i = 0; i < n; i ++) {
            unordered_set<int> st;
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == '.') continue;
                int val = (board[i][j] - '0');
                if (st.count(val)) {
                    return false;
                }
                else st.insert(val);
            }

            st.clear();

            for (int j = 0; j < n; j ++) {
                if (board[j][i] == '.') continue;
                int val = (board[j][i] - '0');
                if (st.count(val)) {
                    return false;
                }
                else st.insert(val);
            }
        }

        // check in 3 x 3 sub-matrix
        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                
                unordered_set<int> st;
                for (int k = i; k < i + 3; k ++) {
                    for (int l = j; l < j + 3; l ++) {
                        if (board[k][l] == '.') continue;
                        int val = (board[k][l] - '0');
                        if (st.count(val)) return false;
                        else st.insert(val);
                    }
                }
            }
        }

        return true;
    }

    // TC : O(N^2)   ~= O(81)   ~= O(1)
    // SC : O(3*N^2) ~= O(3*81) ~= O(1)
    bool approach_2(vector<vector<char>> &board) {
        unordered_set<string> st;
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') continue;

                string row = string(1, board[i][j]) + "ROW" + to_string(i);
                string col = string(1, board[i][j]) + "COL" + to_string(j);
                string box = string(1, board[i][j]) + "BOX" + to_string(i/3) + "_" + to_string(j/3);

                if (st.count(row) || st.count(col) || st.count(box))
                    return false;

                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        return true;
    }

    // TC : O(1)
    // SC : O(1)
    bool approach_3(vector<vector<char>> &board) {
        int row[9] = {0}, col[9] = {0}, box[9] = {0};
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') continue;

                int val    = (board[i][j] - '1');    // 0-based indexing(0...8)
                int mask   = (1 << val);
                int boxIdx = (i / 3) * 3 + (j / 3);

                if ((row[i] & mask) || (col[j] & mask) || (box[boxIdx] & mask))
                    return false;

                row[i]      |= mask;
                col[j]      |= mask;
                box[boxIdx] |= mask;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // return approach_1(board);    // simple
        // return approach_2(board);    // for each cell store strings in set : val+row, val+col, val+box
        return approach_3(board);    // Optimize using bitmask instead of strings for each row, col, box
    }
};
// https://leetcode.com/problems/n-queens/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_set<int> column;    // To check upward has queen
    unordered_set<int> leftUpDiag;  // To check if right upward diagonal has queen
    unordered_set<int> rightUpDiag;  // To check if left upward diagonal has queen

    void solveFast(vector<vector<string>>& result, vector<string>& board, int n, int row) {
        if (row >= n) { // reached out of the board : successfully palced all Queens
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col ++) {                
            
            if (column.find(col) != column.end() || 
                rightUpDiag.find(row + col) != rightUpDiag.end() ||
                leftUpDiag.find (row - col) != leftUpDiag.end()) {
                    continue;
            }

            // if nothing found in set then insert it into set
            column.insert(col);
            leftUpDiag.insert (row - col);
            rightUpDiag.insert(row + col);

            board[row][col] = 'Q';
            solveFast(result, board, n, row + 1);   // try placing queen in next row

            // while backtracking erase values from set
            column.erase(col);
            leftUpDiag.erase (row - col);
            rightUpDiag.erase(row + col);

            board[row][col] = '.';
        }

    }

    bool isValid(vector<string>& board, int n, int row, int col) {
        // Check if a queen is already placed : UPWARD
        for (int i = row - 1; i >= 0; i --) {
            if (board[i][col] == 'Q') 
                return false;
        }

        // Check if a queen is already palced : LEFT UPWARD DIAGONAL
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i --, j --) {
            if (board[i][j] == 'Q')
                    return false;
        }

        // Check if a queen is already palced : RIGHT UPWARD DIAGONAL
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i --, j ++) {
            if (board[i][j] == 'Q')
                    return false;
        }

        return true;
    }

    void solve(vector<vector<string>>& result, vector<string>& board, int n, int row) {
        if (row >= n) { // reached out of the board : successfully palced all Queens
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col ++) {
            
            if (isValid(board, n, row, col)) {
                
                board[row][col] = 'Q';
                solve(result, board, n, row + 1);   // try placing queen in next row
                board[row][col] = '.';              // backtrack
            }
        }

    }

    // TC : O(N!)
    // SC : O(1) + O(N) : space used by recursive stack
    vector<vector<string>> approach_1(int n) {
        vector<vector<string>> result;

        vector<string> board(n, string(n, '.'));
        solve(result, board, n, 0);    // queen placed in 0th row

        return result;
    }

    // TC : O(N!)
    // SC : O(N) + O(N) => space used by set + space used by recursive stack
    vector<vector<string>> approach_2(int n) {
        vector<vector<string>> result;

        vector<string> board(n, string(n, '.'));
        solveFast(result, board, n, 0);    // queen placed in 0th row

        return result;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        // return approach_1(n); 

        return approach_2(n);   // isValid fn Optimized using set  
    }
};
// https://leetcode.com/problems/number-of-paths-with-max-score/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    const int M = 1e9 + 7;
    typedef pair<int, int> P;
    P dp[101][101];

    int getVal(char ch) {
        return (ch == 'X' || ch == 'S') ? 0 : ch - '0';
    }

    bool isValid(int i, int j, vector<string>& board) {
        return (i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X');
    }

    P solve(int i, int j, vector<string>& board) {
        if (board[i][j] == 'E') {
            return {0, 1};  // {score, pathCnt}
        }

        if (board[i][j] == 'X') {
            return {0, 0};
        }

        if (dp[i][j] != make_pair(-1, -1)) {
            return dp[i][j];
        }

        int upScore   = 0, upPath   = 0;
        int leftScore = 0, leftPath = 0;
        int diagScore = 0, diagPath = 0;

        if (isValid(i - 1, j, board)) {    // up
            auto [score, pathCnt] = solve(i - 1, j, board);
            upScore = score;
            upPath  = pathCnt;

            if (upPath > 0) {
                upScore += getVal(board[i][j]);
            }
        }

        if (isValid(i, j - 1, board)) {    // left
            auto [score, pathCnt] = solve(i, j - 1, board);
            leftScore = score;
            leftPath  = pathCnt;

            if (leftPath > 0) {
                leftScore += getVal(board[i][j]);
            }
        }

        if (isValid(i - 1, j - 1, board)) {    // diag
            auto [score, pathCnt] = solve(i - 1, j - 1, board);
            diagScore = score;
            diagPath  = pathCnt;

            if (diagPath > 0) {
                diagScore += getVal(board[i][j]);
            }
        }

        int bestScore = 0, bestPath = 0;
        if (upScore == leftScore && leftScore == diagScore) {
            bestScore = upScore;
            bestPath  = upPath + leftPath + diagPath;
        } else if (upScore == leftScore) {
            bestScore = upScore;
            bestPath  = upPath + leftPath;
            if (diagScore > bestScore || (diagScore == bestScore && diagPath > bestPath)) {
                bestScore = diagScore; bestPath  = diagPath;
            }
        } else if (leftScore == diagScore) {
            bestScore = leftScore;
            bestPath  = leftPath + diagPath;
            if (upScore > bestScore || (upScore == bestScore && upPath > bestPath)) {
                bestScore = upScore; bestPath  = upPath;
            }
        } else {
            bestScore = upScore; bestPath = upPath;
            if (leftScore > bestScore || (leftScore == bestScore && leftPath > bestPath)) {
                bestScore = leftScore; bestPath = leftPath;
            }

            if (diagScore > bestScore || (diagScore == bestScore && diagPath > bestPath)) {
                bestScore = diagScore; bestPath = diagPath;
            }
        }

        return dp[i][j] = {bestScore, bestPath % M};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        memset(dp, -1, sizeof(dp));
        auto result = solve(n - 1, n - 1, board);
        return {result.first, result.second};
    }
};
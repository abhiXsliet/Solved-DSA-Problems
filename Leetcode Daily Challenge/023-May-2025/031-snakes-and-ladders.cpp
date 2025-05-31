// https://leetcode.com/problems/snakes-and-ladders/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    pair<int, int> getCoordinates(int num, int n) {
        int row_top = (num - 1) / n;
        int row_bottom = (n - 1) - row_top;

        int col = (num - 1) % n;
        if ((n % 2 == 1 && row_bottom % 2 == 1) || (n % 2 == 0 && row_bottom % 2 == 0)) {
            col = (n - 1) - col;
        }

        return {row_bottom, col};
    }
public:
    // TC : O(N^2)
    // SC : O(N^2)
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        queue<int> q;
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        visited[n - 1][0] = true;
        q.push(1);
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size --) {
                int fVal = q.front();
                q.pop();

                if (fVal == n * n) return steps;

                for (int i = 1; i <= 6; i ++) {
                    int newVal = fVal + i;
                    if (newVal > n * n) break;

                    pair<int, int> it = getCoordinates(newVal, n);
                    int r = it.first;
                    int c = it.second;

                    if (visited[r][c]) continue;

                    visited[r][c] = true;

                    if (board[r][c] == -1) {
                        q.push(newVal);
                    } else {
                        q.push(board[r][c]);
                    }
                }
            }
            steps ++;
        }   

        return -1;
    }
};
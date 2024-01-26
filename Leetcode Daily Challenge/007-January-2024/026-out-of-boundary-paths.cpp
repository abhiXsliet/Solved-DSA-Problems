// https://leetcode.com/problems/out-of-boundary-paths/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    int M, N;
    int MOD = 1e9 + 7;
    vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dp[51][51][51];
    
    // TC : O(4^maxMoves) -> Recursive
    // SC : O(Height of Recursive Tree) -> At worst O(maxMoves)

    // TC : O(N * M * maxMoves) -> Recursion + Memoization
    // SC : O(N * M * maxMoves) -> Recursion + Memoization
    int solveDFS(int maxMove, int startRow, int startCol) {
        if (startRow < 0 || startRow >= M || startCol < 0 || startCol >= N) {
            return 1;   // Found one path out of grid
        }

        if (maxMove <= 0) {
            return 0;
        }
        
        if (dp[maxMove][startRow][startCol] != -1) 
            return dp[maxMove][startRow][startCol];

        int result = 0;
        for (auto& dir : directions) {
            int nRow = startRow + dir[0];
            int nCol = startCol + dir[1];

            result = ( result + solveDFS(maxMove - 1, nRow, nCol) ) % MOD; 
        }
        return dp[maxMove][startRow][startCol] = result;
    }

    // TC : O(N * M * maxMoves) 
    // SC : O(N * M * maxMoves) 
    int solve_tab(int maxMove, int startRow, int startCol) {
        // dp[k][i][j] = total no. of possible paths leading to out of bound when you are at [i][j] with k-moves
        int dp[51][50][50];
        memset(dp, 0, sizeof(dp));

        for (int k = 1; k <= maxMove; k++) {
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {

                    for (auto& dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];

                        if (x < 0 || x >= M || y < 0 || y >= N) {
                            
                            dp[k][i][j] = (dp[k][i][j] + 1) % MOD; 
                        }
                        else {
                            dp[k][i][j] = (dp[k][i][j] + dp[k - 1][x][y]) % MOD;
                        }
                    }
                }
            }
        }
        return dp[maxMove][startRow][startCol];
    }

    // TC : O(N * M * maxMoves)
    // SC : O(N * M)
    int solve_so(int maxMove, int startRow, int startCol) {
        // To Find    : given x-moves, how many ways to reach [i][j] ? 
        // we'll find : with x-1 moves, how many ways to reach ([i-1][j], [i+1][j], [i][j+1], [i][j-1]). 
        // dp[k][i][j] = given some no. of moves(k = 1, 2, ...), how many ways to reach [i][j]
        
        vector<vector<int>> dp(50, vector<int>(50));
        
        dp[startRow][startCol] = 1;
        int result             = 0;

        for (int k = 1; k <= maxMove; k++) {

            vector<vector<int>> temp(50, vector<int>(50));

            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {

                    for (auto& dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];

                        if (x < 0 || x >= M || y < 0 || y >= N) {
        
                            result = (result + dp[i][j]) % MOD; 
                        }
                        else {
                            // temp[x][y] : no. of ways to reach [x][y] in k moves
                            // dp[i][j]   : no. of ways to reach [i][j] in k - 1 moves since it is neighbour of x, y
                            temp[x][y] = (temp[x][y] + dp[i][j]) % MOD;
                        }
                    }
                }
            }
            dp = temp;
        }

        return result;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M = m;
        N = n;
        // memset(dp, -1, sizeof(dp));
        // return solveDFS(maxMove, startRow, startColumn);

        // return solve_tab(maxMove, startRow, startColumn);

        return solve_so(maxMove, startRow, startColumn);
    }
};
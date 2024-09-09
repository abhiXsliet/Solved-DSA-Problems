// https://leetcode.com/contest/weekly-contest-414/problems/maximum-number-of-moves-to-kill-all-pawns/



#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n + n * 2^n)
// - BFS: Called 'n' times. Since it operates on a fixed 50x50 chessboard, each BFS takes constant O(1) time.
// - Solve Function: Visits and computes for O(n * 2^n) states in the DP table.

// Space Complexity: O(n * 2^n)
// - The DP table requires O(n * 2^n) space.

class Solution {
private:
    vector<vector<int>> directions {{-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {2, 1}, {2, -1}, {-1, -2}, {1, -2}};
    
    int dp[51][1 << 15];    // dp[51][2][1 << 15] : state of alice can be tolrated


    // TC : O(N * 2^N) Where N = Size of pos
    // SC : O(N * 2^N)
    int solve(int idx, bool alice, int mask, int n, vector<vector<int>>& minDist) {
        if (mask == 0) // all pawns choosen 
            return 0;
        
        if (dp[idx][mask] != -1)
            return dp[idx][mask];

        int result = alice == 1 ? -1 : 1e9;

        for (int i = 1; i < n; i ++) {  // pawns starts from 1
            
            if ( mask & (1 << (i - 1)) ) { // check if the pawns is available to pick
                int moves = minDist[idx][i];

                if (alice) {
                    result = max( result, moves + solve(i, 0, (mask ^ (1 << (i - 1))), n, minDist) );
                } else {
                    result = min( result, moves + solve(i, 1, (mask ^ (1 << (i - 1))), n, minDist) );
                }
            } 
        }

        return dp[idx][mask] = result;
    }

    // TC : O(50 * 50) ~= O(1)
    // SC : O(50 * 50) ~= O(1)
    void BFS(int x, int y, int index, int n, vector<vector<int>>& pos, vector<vector<int>>& minDist) {
        queue<pair<int, int>> que;
        vector<vector<int>> t(50, vector<int>(50, -1)); // t[i][j] : min dist from t[x][y] to t[i][j]
        
        que.push({x, y});
        t[x][y] = 0;

        while (!que.empty()) {
            auto [currX, currY] = que.front();
            que.pop();

            for (auto& dir : directions) {
                int newX = currX + dir[0];
                int newY = currY + dir[1];

                if (newX >= 0 && newX < 50 && newY >= 0 && newY < 50 && t[newX][newY] == -1) {
                    t[newX][newY] = 1 + t[currX][currY];
                    que.push({newX, newY});
                }
            }
        }

        for (int i = 0; i < pos.size(); i ++) {
            int i_            = pos[i][0];
            int j_            = pos[i][1];
            minDist[index][i] = t[i_][j_];
        }
    }
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = positions.size();
        
        // Insert the knight into positions to find the min. dist from pos[i] to pos[j]
        vector<vector<int>> pos;
        pos.push_back({kx, ky});
        for (auto& p : positions) {
            pos.push_back(p);
        }
        
        // minDist[r][c] : min dist from pos[i][j] to pos[i][0...n]
        vector<vector<int>> minDist(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n + 1; i ++) {
            int x = pos[i][0];
            int y = pos[i][1];
            BFS(x, y, i, n + 1, pos, minDist);
        }

        // Now play starts through alice and explore all cases
        bool alice = 1;
        int mask   = (1 << n) - 1;  // (1 << n) - 1 : selection of pons no.
        int index  = 0; // knight is at the 0-index
        memset(dp, -1, sizeof(dp));
        return solve(index, alice, mask, n + 1, minDist);  
    }
};
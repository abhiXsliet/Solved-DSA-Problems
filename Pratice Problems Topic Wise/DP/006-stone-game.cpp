// https://leetcode.com/problems/stone-game/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp[2][501][501];

    bool solve(vector<int>& piles, int n, bool takeA, int i, int j, int aliceS, int bobS) {
        if (i >= n || j < 0)
            return aliceS > bobS;

        if (dp[takeA][i][j] != -1)
            return dp[takeA][i][j];

        int val_1 = 0, val_2 = 0;
        int val_3 = 0, val_4 = 0;
        if (takeA) {
            val_1 = piles[i] + solve(piles, n, 0, i + 1, j, aliceS, bobS);
            val_2 = piles[j] + solve(piles, n, 0, i, j - 1, aliceS, bobS);
            aliceS = max(val_1, val_2);
        } else {
            val_3 = piles[i] + solve(piles, n, 1, i + 1, j, aliceS, bobS);
            val_4 = piles[j] + solve(piles, n, 1, i, j - 1, aliceS, bobS);
            bobS   = max(val_3, val_4);
        }

        return dp[takeA][i][j] = aliceS > bobS;
    }
public:
    bool stoneGame(vector<int>& piles) {
        int aliceS = 0;
        int bobS = 0;
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        return solve(piles, n, 1, 0, n - 1, aliceS, bobS);
    }
};
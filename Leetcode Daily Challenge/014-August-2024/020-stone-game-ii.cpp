// https://leetcode.com/problems/stone-game-ii/?envType=daily-question&envId=2024-08-20




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp[101][2][101];

    // TC : O(N^3)  : a loop of n for every states
    // SC : O(N^3)
    int solve(vector<int>& piles, int n, int M, bool takeA, int idx) {
        if (idx >= n) return 0;

        if (dp[M][takeA][idx] != -1)
            return dp[M][takeA][idx];

        int aliceS = takeA == 1 ? INT_MIN : INT_MAX;
        int stones = 0;

        for (int x = 1; x <= min(2*M, n-idx); x ++) { // x no. of tiles can be choosen from players
            
            stones += piles[idx + x - 1];

            if (takeA) {
                int val = stones + solve(piles, n, max(M, x), 0, idx + x);
                aliceS  = max(aliceS, val);

            } else {    // catch : expect the min profit from opponent
                int val = solve(piles, n, max(M, x), 1, idx + x);
                aliceS  = min(aliceS, val);
            }
        }
        
        return dp[M][takeA][idx] = aliceS;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int M = 1;
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        return solve(piles, n, M, 1, 0);
    }
};
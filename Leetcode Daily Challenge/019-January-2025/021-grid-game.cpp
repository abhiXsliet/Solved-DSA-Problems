// https://leetcode.com/problems/grid-game/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    // TC : O(N)
    // SC : O(1)
    ll gridGame(vector<vector<int>>& grid) {
        ll n = grid[0].size();
        ll topSum = 0;
        for (ll c = 0; c < n; c ++) {
            topSum += grid[0][c];
        } 
        ll bottomSum = 0;
        ll minScoreRobotTwo = topSum;
        for (ll c = 0; c < n; c ++) {
            topSum    -= grid[0][c];
            bottomSum += c > 0 ? grid[1][c - 1] : 0;
            // Both robots play optimally, so Robot-2 chooses the maximum of the remaining options after Robot-1's move.
            ll roboTwo = max(topSum, bottomSum);    
            minScoreRobotTwo = min(minScoreRobotTwo, roboTwo);
        }
        return minScoreRobotTwo;
    }
};
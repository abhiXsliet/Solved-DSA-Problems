// https://leetcode.com/problems/grid-game/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    // TC : O(N)
    // SC : O(N) + O(N) Where N = No. of Columns
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        
        vector<ll> top(n), bottom(n);
        top[0]    = grid[0][0];
        bottom[0] = grid[1][0];

        for (int i = 1; i < n; i++) {
            top[i]    = top[i - 1] + grid[0][i];
            bottom[i] = bottom[i - 1] + grid[1][i];
        }

        ll res = LONG_MAX;
        for (int i = 0; i < n; i++) {
            ll topVal    = top[n - 1] - top[i];
            ll bottomVal = i > 0 ? bottom[i - 1] : 0;

            ll secondRob = max(topVal, bottomVal);
            res    = min(res, secondRob);
        }
        return res;
    }
};
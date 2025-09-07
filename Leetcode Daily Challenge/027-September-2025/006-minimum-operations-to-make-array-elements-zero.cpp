// https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    using ll = long long;

    ll getSteps(ll l, ll r) {
        // L...R   : Steps = ?  // R = L * 4 - 1
        // 1...3   : Steps = 1
        // 4...15  : Steps = 2
        // 16...63 : Steps = 3
        
        ll L = 1, step = 1;
        ll stepsToReachZero = 0;

        while (r >= L) {
            ll R = L * 4 - 1;

            ll start = max(L, l);
            ll end   = min(R, r);

            if (start <= end) 
                stepsToReachZero += ((end - start + 1) * step);

            step += 1;
            L    *= 4;
        }

        return stepsToReachZero;
    }
public:
    // TC : O(Q * log4(max(qr)))
    // SC : O(1)
    long long minOperations(vector<vector<int>>& queries) {
        ll result = 0;

        for (vector<int> &query : queries) {
            ll l = query[0], r = query[1];

            ll steps = getSteps(l, r);

            result += (steps + 1) / 2;  // ceil value
        }

        return result;
    }
};
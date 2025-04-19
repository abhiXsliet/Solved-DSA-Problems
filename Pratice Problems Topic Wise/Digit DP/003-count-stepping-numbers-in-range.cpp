// https://leetcode.com/problems/count-stepping-numbers-in-range/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    const int M = 1e9 + 7;
    ll dp[101][2][2][10];

    ll solve(int idx, bool tight, bool isValidNum, int prevD, string &s) {
        if (idx == s.length()) {
            return isValidNum;
        }

        if (dp[idx][tight][isValidNum][prevD] != -1)
            return dp[idx][tight][isValidNum][prevD];

        ll ans = 0;
        int limit = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= limit; d ++) {
            bool newTight = tight & (d == limit);
            
            if (!isValidNum && d == 0) {   // handle leading zeros
                ans += (solve(idx + 1, newTight, false, prevD, s) % M);
            } else if (!isValidNum && d) {  // considering first nonzero digit as a number
                ans += (solve(idx + 1, newTight, true, d, s) % M);
            } else if (abs(prevD - d) == 1) {
                ans += (solve(idx + 1, newTight, true, d, s) % M);
            }
        }

        return dp[idx][tight][isValidNum][prevD] = ans;
    }
public:
    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        ll countNum1 = solve(0, 1, 0, 0, low);

        memset(dp, -1, sizeof(dp));
        ll countNum2 = solve(0, 1, 0, 0, high);

        bool isLowStepping = true;
        // low is inclusive, so check if low is a stepping number
        for (int i = 1; i < low.length(); i ++) {
            if (abs(low[i] - low[i - 1]) != 1) {
                isLowStepping = false;
                break;
            }
        }
        if (isLowStepping) countNum1 --;    // countNum1 is holding stepping no. counts from 0 to (low - 1)

        return (((countNum2 - countNum1) % M) + M) % M;
    }
};
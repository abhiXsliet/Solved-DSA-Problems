// https://leetcode.com/problems/number-of-digit-one/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    ll dp[10][2][10];

    ll solve(int idx, bool tight, int cntOnes, string &str) {
        if (idx == str.length()) {
            return cntOnes;
        }

        if (dp[idx][tight][cntOnes] != -1)
            return dp[idx][tight][cntOnes];

        ll ans = 0;
        int limit = tight ? str[idx] - '0' : 9;

        for (int d = 0; d <= limit; d ++) {
            bool newTight = tight & (d == limit);
            ans += solve(idx + 1, newTight, cntOnes + (d == 1), str);
        }
        return dp[idx][tight][cntOnes] = ans;
    }
public:
    int countDigitOne(int n) {
        string str = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 0, str);
    }
};
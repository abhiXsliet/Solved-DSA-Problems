// https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    ll dp[10][2][6][6][20][2];  // index, tight, oddCnt, evenCnt, remainder, validNumber(to handle leading zeros)

    ll solve(int idx, bool tight, int oCnt, int eCnt, int rem, bool validNum, string &s, int k) {
        if (idx >= s.length()) {
            return ((oCnt == eCnt) && !rem);
        }
        
        // pruning
        if ((oCnt > 5) || (eCnt > 5))
            return 0;

        if (dp[idx][tight][oCnt][eCnt][rem][validNum] != -1)
            return dp[idx][tight][oCnt][eCnt][rem][validNum];

        ll ans = 0;
        int limit = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= limit; d ++) {
            bool newTight = tight && (d == limit);
            if (!validNum && d == 0) {
                ans += (solve(idx + 1, newTight, oCnt, eCnt, rem, false, s, k));
            } else if (d % 2) {
                ans += (solve(idx + 1, newTight, oCnt + 1, eCnt, (rem * 10 + d) % k, true, s, k));
            } else {
                ans += (solve(idx + 1, newTight, oCnt, eCnt + 1, (rem * 10 + d) % k, true, s, k));
            }
        }

        return dp[idx][tight][oCnt][eCnt][rem][validNum] = ans;
    }
public:
    // TC : O(Total States * 10)
    // SC : O(Total States)
    int numberOfBeautifulIntegers(int low, int high, int k) {
        memset(dp, -1, sizeof(dp));
        string h = to_string(high);
        ll countNum1 = solve(0, 1, 0, 0, 0, 0, h, k);

        memset(dp, -1, sizeof(dp));
        string l = to_string(low - 1);
        ll countNum2 = solve(0, 1, 0, 0, 0, 0, l, k);

        return (countNum1 - countNum2);
    }
};
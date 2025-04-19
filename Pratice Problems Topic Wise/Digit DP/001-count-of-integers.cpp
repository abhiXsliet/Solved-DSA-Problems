// https://leetcode.com/problems/count-of-integers/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    const int M = 1e9 + 7;
    ll dp[23][2][401];

    ll solve(int idx, bool tight, int sum, string &s, int &min_sum, int &max_sum) {
        if (idx >= s.length()) {
            return sum >= min_sum && sum <= max_sum;
        }

        if (dp[idx][tight][sum] != -1)
            return dp[idx][tight][sum];

        ll ans = 0;
        int limit = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= limit; d ++) {
            bool newTight = tight & (d == limit);
            ans += (solve(idx + 1, newTight, sum + d, s, min_sum, max_sum) % M);
        }

        return dp[idx][tight][sum] = ans;
    }
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        ll countNum1 = solve(0, 1, 0, num1, min_sum, max_sum);

        memset(dp, -1, sizeof(dp));
        ll countNum2 = solve(0, 1, 0, num2, min_sum, max_sum);

        int sum = 0;
        for (char &d : num1) {
            sum += (d - '0');
        }

        if (sum >= min_sum && sum <= max_sum)
            countNum1 --;

        return (((countNum2 - countNum1) % M) + M) % M;
    }
};
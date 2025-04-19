// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    ll dp[10][2][2];

    ll solve(int idx, bool tight, bool isValidNum, vector<string> &digits, string &str) {
        if (idx >= str.length()) 
            return isValidNum;

        if (dp[idx][tight][isValidNum] != -1)
            return dp[idx][tight][isValidNum];

        ll ans = 0;
        if (!isValidNum) // making no.s by adding leading zeros
            ans += (solve(idx + 1, false, false, digits, str));

        int limit = tight ? str[idx] - '0' : 9; // generated no.s should be within limit

        for (auto &s : digits) {
            int d = stoi(s);
            if (d > limit) break;   // breaking out since the digits are in sorted form

            bool newTight = (tight & (d == limit));
            ans += solve(idx + 1, newTight, true, digits, str);
        }

        return dp[idx][tight][isValidNum] = ans;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string str = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 0, digits, str);   
    }
};
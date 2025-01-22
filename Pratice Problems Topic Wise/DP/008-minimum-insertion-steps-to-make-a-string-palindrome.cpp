// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int LCS(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i >= s1.length() || j >= s2.length())
            return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int incl = 0, excl = 0;
        if (s1[i] == s2[j]) {
            incl = 1 + LCS(s1, s2, i + 1, j + 1, dp);
        } else {
            excl = max(LCS(s1, s2, i + 1, j, dp), LCS(s1, s2, i, j + 1, dp));
        }
        return dp[i][j] = max(incl, excl);
    }

    int LPS(string s1) {
        int n = s1.length();
        string s2 = s1;
        reverse(begin(s2), end(s2));
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return LCS(s1, s2, 0, 0, dp);
    }
public:
    int minInsertions(string s) {
        return s.length() - LPS(s);
    }
};
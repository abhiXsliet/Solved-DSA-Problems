// https://leetcode.com/problems/longest-palindromic-subsequence-after-at-most-k-operations/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // return longestPalindromicSubseq. made from s.substr[i...j]
    int solve(string &s, int k, int i, int j, vector<vector<vector<int>>> &dp) {
        if (i >= j) {
            return i == j;
        }

        if (dp[k][i][j] != -1) return dp[k][i][j];

        // not match
        int result = max(solve(s, k, i + 1, j, dp), solve(s, k, i, j - 1, dp));

        // match
        int c = abs(s[i] - s[j]);
        int minCost = min(c, 26 - c);
        if (k >= minCost) {
            result = max(result, 2 + solve(s, k - minCost, i + 1, j - 1, dp));
        }

        return dp[k][i][j] = result;
    }
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.length();
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return solve(s, k, 0, n - 1, dp);
    }
};
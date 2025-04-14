// https://leetcode.com/problems/longest-palindrome-after-substring-concatenation-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;
    int memo[1001][1001];

    int solve(string &s, string &t, vector<int> &startToEnd, vector<int> &endToStart, int i, int j) {
        if (i >= m || j < 0)
            return 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        int max_palin_len = max(startToEnd[i], endToStart[j]);

        if (s[i] == t[j]) {
            bool atEndOfS   = (i == m - 1);
            bool atStartOfT = (j == 0);

            int val = 0;
            if (atEndOfS && atStartOfT) {
                val = 0;
            } else if (atEndOfS) {
                val = endToStart[j - 1];
            } else if (atStartOfT) {
                val = startToEnd[i + 1];
            } else {
                val = solve(s, t, startToEnd, endToStart, i + 1, j - 1);
            }

            max_palin_len = max(max_palin_len, 2 + val);
        }
        
        return memo[i][j] = max_palin_len;
    }

    void getLPS(string &s, vector<int> &store, bool isSTartToEnd) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int gap = 0; gap < n; gap ++) {
            for (int i = 0, j = gap; j < n; i ++, j ++) {
                if (gap == 0) {
                    dp[i][j] = 1;
                } else if (gap == 1 && (s[i] == s[j])) {
                    dp[i][j] = 2;
                } else {
                    if (s[i] == s[j] && dp[i + 1][j - 1] != 0)
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                }

                if (isSTartToEnd) { 
                    store[i] = max(store[i], dp[i][j]);
                } else {  
                    store[j] = max(store[j], dp[i][j]);
                }
            }
        }
    }
public:
    int longestPalindrome(string s, string t) {
        m = s.length(), n = t.length();

        vector<int> startstartToEnd(m, 1), endToStart(n, 1);
        getLPS(s, startstartToEnd, 1);  // stores max-palindromic-len starting from i to end
        getLPS(t, endToStart, 0);       // stores max-palindromic-len starting from 0 to ending at j

        memset(memo, -1, sizeof(memo));
        
        int ans = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = n - 1; j >= 0; j --) {
                ans = max(ans, solve(s, t, startstartToEnd, endToStart, i, j));
            }
        }
        return ans;
    }
};
// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int M = 1e9 + 7;
    int t[1001][10001];
    typedef long long ll;
    int m;
    int n;

    // TC : O(M * N)
    // SC : O(1)
    int solve_1(vector<vector<ll>>& freq, string &target, int i, int j) {
        if (i == n) return 1;
        if (j == m) return 0;

        if (t[i][j] != -1) return t[i][j];

        int take     = (freq[target[i] - 'a'][j] * solve_1(freq, target, i + 1, j + 1) % M) % M;
        int not_take = solve_1(freq, target, i, j + 1) % M;

        return t[i][j] = (take + not_take) % M;
    }

    // TC : O(M * N)
    // SC : O(1)
    int countTotalWays(vector<vector<int>>& t, string& target, int tIdx, int wIdx, vector<vector<int>>& dp) {
        if (tIdx == n) return 1; // Successfully formed the target
        if (wIdx == m) return 0; // Ran out of columns before completing the target

        if (dp[tIdx][wIdx] != -1) return dp[tIdx][wIdx];

        int ways = countTotalWays(t, target, tIdx, wIdx + 1, dp);

        // Use current column if the target character exists
        int targetChar = target[tIdx] - 'a';
        if (t[wIdx][targetChar]) {
            ways = (ways + (ll)t[wIdx][targetChar] * countTotalWays(t, target, tIdx + 1, wIdx + 1, dp) % M) % M;
        }

        return dp[tIdx][wIdx] = ways;
    }

    // TC : O(N * N * M)
    // SC : O(N * M)
    int approach_1(vector<string>& words, string &tar, int idx, int j) {
        if (j >= tar.length()) return 1;

        if (t[idx][j] != -1) return t[idx][j];

        int total = 0;
        for (string &word : words) {
            for (int i = idx; i < word.length(); i ++) {
                if (word[i] == tar[j]) {
                    total += (approach_1(words, tar, i + 1, j + 1) % M);
                    total %= M;
                }
            }
        }
        return t[idx][j] = total;
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int approach_2(vector<string>& words, string target) {
        // Frequency table: t[i][c] = count of character 'c' at column 'i'
        vector<vector<int>> t(m, vector<int>(26, 0));
        for (string& word : words) {
            for (int i = 0; i < m; i++) {
                t[i][word[i] - 'a']++;
            }
        }

        // DP table: dp[tIdx][wIdx] = number of ways to form target[tIdx:] using words[wIdx:]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return countTotalWays(t, target, 0, 0, dp);
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int simplified_approach_2(vector<string>& words, string &target, int i, int j) { 
        vector<vector<ll>> freq(26, vector<ll>(m, 0));
        for (string &word : words) {
            for (int i = 0; i < m; i ++) {
                freq[word[i] - 'a'][i] ++;
            }
        }
        return solve_1(freq, target, 0, 0);
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int approach_3(vector<string>& words, string target) {
        vector<vector<ll>> freq(26, vector<ll>(m, 0));
        for (string &word : words) {
            for (int i = 0; i < m; i ++) {
                freq[word[i] - 'a'][i] ++;
            }
        }

        // dp[i][j] = total ways of forming target of length i using j leftmost columns
        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
        dp[0][0] = 1;

        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (j < m)
                    dp[i][j + 1]     = (dp[i][j + 1] + dp[i][j]) % M;
                
                if (i < n && j < m)
                    dp[i + 1][j + 1] = (freq[target[i] - 'a'][j] * dp[i][j] + dp[i + 1][j + 1]) % M;
            }
        }

        return dp[n][m];
    }
public:
    int numWays(vector<string>& words, string target) {
        m = words[0].length(), n = target.length();
        memset(t, -1, sizeof(t));

        // return approach_1(words, target, 0, 0);  // BRUTE

        // return approach_2(words, target);        // Rec + Memo

        // return simplified_approach_2(words, target, 0, 0);   // Rec + Memo

        return approach_3(words, target);        // Bottom Up
    }
};
// https://leetcode.com/problems/string-compression-ii/



#include <bits/stdc++.h>
using namespace std;

int t[101][27][101][101];   // memory allocation is done on heap outside class
                            // while inside class memory allocation is done on stack
class Solution {
private:
    // TC : O(n * 26 * n * k) ~ O(n^2 * k)
    // SC : O(n^2 * k)
    int solve_mem_1(string& s, int idx, int prev_char, int freq, int k) {
        if (k < 0) {
            return INT_MAX;
        }

        if (idx >= s.length()) {
            return 0;
        }

        if (t[idx][prev_char][freq][k] != -1)
            return t[idx][prev_char][freq][k];

        int delete_i = solve_mem_1(s, idx+1, prev_char, freq, k - 1);

        int keep_i = 0;

        if (s[idx] - 'a' != prev_char) {
            keep_i = 1 + solve_mem_1(s, idx+1, s[idx] - 'a', 1, k);
        }
        else {
            int one_more_addition = 0;  // RLE
            if (freq == 1 || freq == 9 || freq == 99)
                one_more_addition = 1;

            keep_i = one_more_addition + solve_mem_1(s, idx+1, prev_char, freq+1, k);
        }

        return t[idx][prev_char][freq][k] = min(delete_i, keep_i);
    }

    // TC : O(n^2 * k)
    // SC : O(n*k)
    int solve_mem_2(string& s, int k, int i, int n, vector<vector<int>>& dp) {
        if (k < 0) 
            return 10000;

        if (i == n || (n - i) <= k) 
            return 0;

        if (dp[k][i] != -1)
            return dp[k][i];

        int delete_i = solve_mem_2(s, k - 1, i + 1, n, dp);

        int keep_i   = INT_MAX;

        int freq     = 0;
        int deleted  = 0;
        int added    = 0;

        for (int j = i; j < n && deleted <= k; j++) {
            if (s[j] == s[i]) {
                freq ++;
                if (freq == 2 || freq == 10 || freq == 100)
                    added ++;
            } else deleted ++;

            keep_i = min(keep_i, 1 + added + solve_mem_2(s, k - deleted, j + 1, n, dp));
        }

        return dp[k][i] = min(delete_i, keep_i);
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        // memset(t, -1, sizeof(t));
        // return solve_mem_1(s, 0, 26, 0, k);

        vector<vector<int>> dp(k + 1, vector<int>(s.length()+1, -1));
        return solve_mem_2(s, k, 0, s.length(), dp);
    }
};
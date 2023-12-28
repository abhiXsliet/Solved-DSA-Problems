// https://leetcode.com/problems/string-compression-ii/



#include <bits/stdc++.h>
using namespace std;

int t[101][27][101][101];   // memory allocation is done on heap outside class
                            // while inside class memory allocation is done on stack
class Solution {
private:
    // TC : O(n * 26 * n * k) ~ O(n^2 * k)
    // SC : O(n^2 * k)
    int solve_mem(string& s, int idx, int prev_char, int freq, int k) {
        if (k < 0) {
            return INT_MAX;
        }

        if (idx >= s.length()) {
            return 0;
        }

        if (t[idx][prev_char][freq][k] != -1)
            return t[idx][prev_char][freq][k];

        int delete_i = solve_mem(s, idx+1, prev_char, freq, k - 1);

        int keep_i = 0;

        if (s[idx] - 'a' != prev_char) {
            keep_i = 1 + solve_mem(s, idx+1, s[idx] - 'a', 1, k);
        }
        else {
            int one_more_addition = 0;  // RLE
            if (freq == 1 || freq == 9 || freq == 99)
                one_more_addition = 1;

            keep_i = one_more_addition + solve_mem(s, idx+1, prev_char, freq+1, k);
        }

        return t[idx][prev_char][freq][k] = min(delete_i, keep_i);
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(t, -1, sizeof(t));
        return solve_mem(s, 0, 26, 0, k);
    }
};
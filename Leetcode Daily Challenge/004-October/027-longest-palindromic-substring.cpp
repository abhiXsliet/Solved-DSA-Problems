// https://leetcode.com/problems/longest-palindromic-substring/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int t[1001][1001];

    // Helper function to expand around a center and return the length of the longest palindrome
    int getExpandedPalinLen(string &s, int i, int j) {
        int n = s.length();
        while (i >= 0 && j < n && s[i] == s[j]) {
            i --, j ++;
        }
        return j - i - 1;
    }

    // TC : O(1) Optimized using previous state calculations
    // SC : O(1)
    bool isPalindrome(string &s, int i, int j) {
        if (i >= j) return 1;

        if (t[i][j] != -1) return t[i][j];

        return t[i][j] = (s[i] == s[j]) ? isPalindrome(s, i + 1, j - 1) : 0;
    }

    // TC : O(N^2)
    // SC : O(N^2)
    string approach_1(string &s) {
        int n = s.length();
        int maxPalinLen = 0;
        int startPalin = -1;

        memset(t, -1, sizeof(t));

        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j ++) {
                if (isPalindrome(s, i, j)) {
                    if (j - i + 1 > maxPalinLen) {
                        maxPalinLen = j - i + 1;
                        startPalin = i;
                    }
                }
            }
        }
        return s.substr(startPalin, maxPalinLen);
    }

    // TC : O(N^2)
    // SC : O(1)
    string approach_2(string &s) {
        int n = s.length();
        int maxPalinLen = 1;
        int startPalin = 0;

        for (int i = 0; i < n; i ++) { 
            int l1 = getExpandedPalinLen(s, i, i);        // centered around 'i' for odd palindrome
            int l2 = getExpandedPalinLen(s, i, i + 1);    // centered b/w 'i' & 'i + 1' for even palindrome

            int curr_max = max(l1, l2);
            if (curr_max > maxPalinLen) {
                maxPalinLen = curr_max;
                startPalin  = i - (curr_max - 1) / 2;
            }
        }
        return s.substr(startPalin, maxPalinLen);
    }

    // TC : O(N^2)
    // SC : O(N^2)
    string approach_3(string &s) {
        int n = s.length();
        // dp[i][j] : string starting at i and ending at j has palindromic len of ?
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int maxi = 0, start = -1;
        for (int gap = 0; gap < n; gap ++) {
            for (int i = 0, j = gap; j < n; i ++, j ++) {
                if (gap == 0) { // palindromic string of len-1
                    dp[i][j] = 1;
                } else if (gap == 1) {  // palindromic string of len-2
                    if (s[i] == s[j]) {
                        dp[i][j] = 2;
                    }   
                } else {    // palindromic string of len more than 2
                    if (s[i] == s[j] && dp[i + 1][j - 1]) {
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j] > maxi) {
                    maxi = dp[i][j];
                    start = i;
                }
            }
        }
        return s.substr(start, maxi);
    }
public:
    string longestPalindrome(string s) {
        // return approach_1(s);    // Optimzied palindrome check using previous calculation in O(1), DP
        // return approach_2(s);    // Expand around center
        return approach_3(s);       // DP approach
    }
};
// https://leetcode.com/problems/palindromic-substrings/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    bool isPalindrome(string& str) {
        int i = 0, j = str.length() - 1;
        while (i < j) {
            if (str[i] != str[j]) 
                return 0;
            i ++;
            j --;
        }
        return 1;
    }
    
    // TC : O(N^3)
    // SC : O(N) -> creating new string for each substring
    int solve_brute(string& s, int n) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int len = i; len < n; len++) {
                string str = s.substr(i, len - i + 1);  // O(N)
                if ( isPalindrome(str) )                // O(N)
                    ans ++;
            }
        }
        return ans;
    }

    int dp[1001][1001];
    // TC : O(N)
    // SC : O(N^2)
    bool checkPalindrome(string& s, int i, int j) {
        if (i > j) return true;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            return dp[i][j] = checkPalindrome(s, i + 1, j - 1);
        }

        return dp[i][j] = false;
    }

    // TC : O(N^2) since for every substring from i to j, which gets calculated only once 
    // SC : O(N^2)
    int solve_better(string& s, int n) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkPalindrome(s, i, j)) ans ++;
            }
        }
        return ans;
    }

    // ------------------------------BLUEPRINT --------------------------------
    // TC : O(N^2)
    // SC : O(N^2)
    int solve_tab_1(string& s, int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // dp[i][j] == 1 => it is a palindromic substring inclusive indices i & j

        int count = 0;
        for (int L = 1; L <= n; L ++) {
           
            for (int i = 0; L + i - 1 < n ; i++) {
                int j = L + i - 1;

                if (i == j) { // single char only
                    dp[i][j] = true;
                }
                else if (i + 1 == j) { // double char only
                    dp[i][j] = (s[i] == s[j]);
                }
                else {  // generic case
                    dp[i][j] = ( (s[i] == s[j]) && (dp[i + 1][j - 1]) );
                }

                if (dp[i][j] == true) count ++;
            }
        }
        return count;
    }

    void check_Palindrome(int i, int j, string& s, int n, int& count) {
        while (i >= 0 && j < n && s[i] == s[j]) {
            count ++;
            i --;
            j ++;
        }
    }
    
    // TC : O(N^2)
    // SC : O(1)
    int solve_tab_2(string& s, int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            // it checks the odd length palindrome
            check_Palindrome(i, i, s, n, count);
            // it checks the even length palindrome
            check_Palindrome(i, i + 1, s, n, count);
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        // return solve_brute(s, s.length());

        // memset(dp, -1, sizeof(dp));
        // return solve_better(s, s.length());

        // return solve_tab_1(s, s.length());

        return solve_tab_2(s, s.length());
    }
};
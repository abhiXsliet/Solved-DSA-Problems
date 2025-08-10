// https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int n;
    vector<vector<int>> dp;
    
    bool isPalindrome(string &s, int i, int j) {
        if (i >= j) return true;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = (s[i] == s[j]) ? isPalindrome(s, i + 1, j - 1) : 0;
    }
    
    int cntPalindromes(string &s, int i, int j) {
        int cntPalindromes = 0;
        while (i >= 0 && j < n) {
            if (s[i] != s[j]) {
                break;
            }
            cntPalindromes += 1;
            i --, j ++;
        }
        return cntPalindromes;
    }
    
    // TC : O(N^2)
    // SC : O(N^2)
    int approach_1(string &s) {
        dp.resize(n + 1, vector<int>(n + 1, -1));
        int cntPalindromicSubstrs = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {  // since palindromes >= 2
                if (isPalindrome(s, i, j)) {
                    cntPalindromicSubstrs += 1;
                }
            }
        }
        return cntPalindromicSubstrs;
    }  
    
    // TC : O(N^2)
    // SC : O(N^2)
    int approach_2(string &s) {
        // dp[i][j] == 1 ? palindrome [i:j] : not palindrome
        dp.resize(n + 1, vector<int>(n + 1, 0));
        
        int cntPalindromicSubstrs = 0;
        for (int len = 1; len <= n; len ++) {
            for (int i = 0; len + i - 1 < n; i ++) {
                int j = len + i - 1;
                
                if (i == j) {   // single char : always palindrome
                    dp[i][j] = 1;
                } else if (i + 1 == j) {    // double char : if matches then palindrome
                    dp[i][j] = (s[i] == s[j]);
                } else {    // For length > 2: ensure the current characters match, and the substring between them is also a palindrome.
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                
                if (len >= 2 && dp[i][j]) {
                    cntPalindromicSubstrs += 1;
                }
            }
        }
        return cntPalindromicSubstrs;
    }  
    
    // TC : O(N^2)
    // SC : O(1)
    int optimal(string &s) {
        int cntPalindromicSubstrs = 0;
        for (int i = 0; i < n; i ++) {
            cntPalindromicSubstrs += cntPalindromes(s, i - 1, i + 1); // for odd len palindromes
            cntPalindromicSubstrs += cntPalindromes(s, i, i + 1);     // for even len palindromes
        }
        return cntPalindromicSubstrs;
    }  
  public:
    int countPS(string &s) {
        n = s.length();
        
        // return brute(s);         // O(N^3) TLE 
        // return approach_1(s);    // palindrome check get memoized (since appending only new char to the previous one)
        return approach_2(s);    // Bottom Up - Blueprint for palindrome related problems
        
        // return optimal(s);    // OPTIMAL : Expand from center for both even and odd len palindromes
    }
};
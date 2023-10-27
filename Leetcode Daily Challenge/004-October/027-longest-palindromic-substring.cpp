// https://leetcode.com/problems/longest-palindromic-substring/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int t[1001][1001];

    // iterative approach to check palindrome 
    bool isPalindrome(string& s, int i, int j) {
        while(i <= j) {
            if(s[i] == s[j])
                i++, j--;
            else return false;
        }
        return true;
    }
    
    bool checkPalindrome(string& s, int i, int j) {
        if (i >= j) 
            return 1;

        if (t[i][j] != -1) 
            return t[i][j];

        if(s[i] == s[j])
            return t[i][j] = checkPalindrome(s, i+1, j-1);

        return t[i][j] = 0;
    }

    // TC = O(N*N*N)
    // SC = O(N*N)
    string solve(string s, int n) {
        memset(t, -1, sizeof(t));

        int maxLen  = 0;
        int startPt = -1;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (checkPalindrome(s, i, j)) {
                    if(j - i + 1 > maxLen) {
                        maxLen  = max(maxLen, j - i + 1);
                        startPt = i;
                    }
                }
            }
        }

        return s.substr(startPt, maxLen);
    }
public:
    string longestPalindrome(string s) {
        return solve(s, s.length());
    }
};
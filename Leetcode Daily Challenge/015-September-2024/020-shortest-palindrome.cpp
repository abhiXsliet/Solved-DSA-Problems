// https://leetcode.com/problems/shortest-palindrome/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(N)
    string approach_1(string s) {
        int n = s.length();
        string rev = s;
        reverse(begin(rev), end(rev));

        for (int i = 0; i < n; i ++) {
            // if prefix of s == suffix of rev
            if (s.substr(0, n - i) == rev.substr(i)) {
                return rev.substr(0, i) + s;
            }
        }

        return rev + s;
    }

    // TC : O(N^2)
    // SC : O(N)
    string approach_2(string s) {
        int n = s.length();
        string rev = s;
        reverse(begin(rev), end(rev));

        for (int i = 0; i < n; i ++) {
            // prefix of s == suffix of rev : memcmp() return 0 if true
            if (!memcmp(s.c_str(), rev.c_str() + i, n - i)) {
                return rev.substr(0, i) + s;
            }
        }

        return rev + s;
    }

    // TC : O(N)
    // SC : O(N)
    vector<int> prefixStore(string s) {
        int n = s.length();
        vector<int> prefix_idx(n, 0);
        
        for (int i = 1; i < n; i ++) {
            int j = prefix_idx[i - 1];
            
            while (j > 0 && s[i] != s[j]) {
                j = prefix_idx[j - 1];
            }

            if (s[i] == s[j]) j ++;
            prefix_idx[i] = j;
        }
        return prefix_idx;
    }

    // TC : O(N)
    // SC : O(N)
    string approach_3(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));

        string temp = s + '-' + rev;

        vector<int> LPS  = prefixStore(temp);
        int commonLenLPS = LPS[LPS.size() - 1];

        string unCommon  = rev.substr(0, s.length() - commonLenLPS);

        return unCommon + s;
    }
public:
    string shortestPalindrome(string s) {
        // return approach_1(s);   // MLE : used substr() fn 

        // return approach_2(s);   // Skip MLE using memcmp() fn

        return approach_3(s);   // KMP  
    }
};
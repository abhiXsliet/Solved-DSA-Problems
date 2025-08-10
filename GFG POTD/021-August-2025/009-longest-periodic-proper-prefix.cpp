// https://www.geeksforgeeks.org/problems/longest-periodic-proper-prefix/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    vector<int> getLPS (string &s) {
        int n = s.length();
        vector<int> lps(n, 0);
        int len = 0, j = 1;
        while (j < n) {
            if (s[len] == s[j]) {
                len += 1;
                lps[j] = len;
                j += 1;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[j] = len;
                    j ++;
                }
            }
        }
        return lps;
    }
    
    // TC : O(N^2)
    // SC : O(1)
    int brute(string &s) {
        int n = s.length();
        int longestProperPrefLen = -1;
        
        for (int len = n - 1; len >= 1; len --) {
            
            string str = s.substr(0, len);
            bool isProperPref = 1;
            
            for (int i = 0; i < n; i ++) {
                if (str[i % len] != s[i]) {
                    isProperPref = 0;
                    break;
                }
            }
            
            if (isProperPref) {
                longestProperPrefLen = len;
                break;
            }
        }
        
        return longestProperPrefLen;
    }
    
    // TC : O(N)
    // SC : O(N)
    int optimal(string &s) {
        int n = s.length();
        
        vector<int> lps = getLPS(s);
        
        int t = lps[n - 1];
        
        if (t == 0) return -1;
        
        while (lps[t - 1] > 0) t = lps[t - 1];
        
        return n - t;
    }
  public:
    int getLongestPrefix(string &s) {
        // return brute(s);
        return optimal(s);
    }
};
// https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(string &s) {
        int n = s.length();
        
        vector<int> lps(n, 0);

        for (int i = 1; i < n; i ++) {
            int j = lps[i - 1];
            
            while (j > 0 && s[i] != s[j]) j = lps[j - 1];
            
            if (s[i] == s[j]) j ++;
            lps[i] = j;
        }
        
        return lps[n - 1];
    }
        
    // TC : O(N)
    // SC : O(N)
    int approach_2(string &s) {
        int n = s.length();
        
        vector<int> lps(n, 0);
        int len = 0, j = 1;
        
        while (j < n) {
            if (s[j] == s[len]) {
                len   += 1;
                lps[j] = len;
                j     += 1;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[j] = len;
                    j ++;
                }
            }
        }
        
        return lps[n - 1];
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_3(string &s) {
        int n = s.length();
        
        // prefixHash[0] = Hash of Prefix using base-1 and mod-1
        // prefixHash[1] = Hash of prefix using base-2 and mod-2
        vector<int> prefixHash(2, 0), suffixHash(2, 0);
        const int base1 = 31, base2 = 37, M1 = 1e9 + 7, M2 = 1e9 + 9;
        int p1 = 1, p2 = 1, ans = 0;
        
        for (int i = 0; i < n - 1; i ++) {
            prefixHash[0] = (prefixHash[0] + (1LL * (s[i] - 'a' + 1) * p1 % M1)) % M1;
            prefixHash[1] = (prefixHash[1] + (1LL * (s[i] - 'a' + 1) * p2 % M2)) % M2;

            suffixHash[0] = (1LL * suffixHash[0] * base1 % M1 + (s[n - i - 1] - 'a' + 1)) % M1;
            suffixHash[1] = (1LL * suffixHash[1] * base2 % M2 + (s[n - i - 1] - 'a' + 1)) % M2;
            
            if (prefixHash == suffixHash) ans = i + 1;
            
            p1 = (1LL * p1 * base1) % M1;
            p2 = (1LL * p2 * base2) % M2;
        }
        
        return ans;
    }
  public:
    int getLPSLength(string &s) {
        // return approach_1(s);    // KMP 
        // return approach_2(s);    // KMP : no while loop
        return approach_3(s);    // Using Rolling Hash: O(1) space
    }
};
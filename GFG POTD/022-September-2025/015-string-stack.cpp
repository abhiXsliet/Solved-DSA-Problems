// https://www.geeksforgeeks.org/problems/string-stack--165812/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        int m = pat.length(), n = tar.length();
        
        // We reverse both strings so we can process them from right-to-left. (processing Left to right have 2-options)
        // Why? Because matching from the end makes "delete" operations easier to simulate:
        // - If characters match, we keep them.
        // - If characters don’t match, we skip 2 chars (append + delete).
        reverse(begin(pat), end(pat));
        reverse(begin(tar), end(tar));
        
        int i = 0, j = 0; 
        
        while (i < m) {
            if (j < n && pat[i] == tar[j]) {
                i++, j++;
            } else {
                i += 2;
            }
        }
        
        return (j == n);
    }
};
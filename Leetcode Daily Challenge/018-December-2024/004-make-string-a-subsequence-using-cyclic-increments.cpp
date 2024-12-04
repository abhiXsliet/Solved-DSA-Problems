// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(max{m, n})
    // SC : O(1)
    bool canMakeSubsequence(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s1[i] == s2[j] || (s1[i] - 'a' + 1) % 26 == s2[j] - 'a') j ++;
    
            // if (s1[i] == s2[j] || s1[i] + 1 == s2[j] || s1[i] - 25 == s2[j]) j++;   // or 

            i ++;
        }
        return j == n;
    }
};
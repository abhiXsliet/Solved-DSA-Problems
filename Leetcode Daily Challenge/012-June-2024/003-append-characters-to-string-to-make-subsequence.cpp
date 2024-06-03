// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(max(N, M))
    // SC : O(1)
    int appendCharacters(string s, string t) {
        int m = s.length(), n = t.length();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                i ++, j ++;
            } else i ++;
        }
        return n - j;
    }
};
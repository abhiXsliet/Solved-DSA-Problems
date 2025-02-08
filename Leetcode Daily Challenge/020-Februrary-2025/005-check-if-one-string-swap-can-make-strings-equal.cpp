// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(M + N)
    // SC : O(1)
    bool areAlmostEqual(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        bool swapped = 0;
        int i = 0, j = m - 1, k = 0, l = n - 1;
        while (i <= j && k <= l) {
            if (s1[i] == s2[k] && s1[j] == s2[l]) {
                i ++, j --, k ++, l --;
            } else if (s1[i] == s2[k] && s1[j] != s2[l]) {
                i ++, k ++;
            } else if (s1[i] != s2[k] && s1[j] == s2[l]) {
                j --, l --;
            } else {
                if (swapped) return false;
                swap(s2[k], s2[l]);
                swapped = 1;
            }
        }
        return true;
    }
};
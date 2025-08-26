// https://www.geeksforgeeks.org/problems/given-two-strings-find-if-first-string-is-a-subsequence-of-second/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(M + N)
    // SC : O(1)
    bool isSubSeq(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s1[i] == s2[j]) {
                i ++, j ++;
            } else j ++;
        }
        return i == m;
    }
};
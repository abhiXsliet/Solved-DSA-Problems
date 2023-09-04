// https://leetcode.com/contest/biweekly-contest-112/problems/check-if-strings-can-be-made-equal-with-operations-ii/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i]) continue;
            int k = 2;
            while (i + k < n) {
                if (s1[i + k] == s2[i]) {
                    swap(s1[i + k], s1[i]);
                    break;
                }
                k += 2;
            }

            k = 2;
            while (i - k >= 0) {
                if (s1[i - k] == s2[i]) {
                    swap(s1[i - k], s1[i]);
                    break;
                }
                k += 2;
            }
        }
        return (s1 == s2);
    }
};

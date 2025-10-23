// https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(N)
    bool brute(string &s) {
        while (s.length() > 2) {
            string temp;
            for (int i = 1; i < s.length(); i ++) {
                temp += (((s[i] - '0') + (s[i - 1] - '0')) % 10) + '0';
            }
            s = temp;
        }
        return s[0] == s[1];
    }
public:
    bool hasSameDigits(string s) {
        return brute(s);
    }
};
// https://leetcode.com/problems/latest-time-you-can-obtain-after-replacing-characters/description/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLatestTime(string s) {
        if (s[0] == '?') {
            s[0] = (s[1] != '?' && s[1] > '1') ? '0' : '1';
        }
        if (s[1] == '?') {
            s[1] = (s[0] == '1') ? '1' : '9';
        }
        if (s[3] == '?') {
            s[3] = '5';
        }
        if (s[4] == '?') {
            s[4] = '9';
        }
        return s;
    }
};

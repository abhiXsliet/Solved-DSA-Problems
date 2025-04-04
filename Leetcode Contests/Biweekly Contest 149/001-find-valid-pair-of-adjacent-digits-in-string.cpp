// https://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findValidPair(string s) {
        int n = s.length();
        vector<int> freq(10, 0);
        for (char &ch : s) {
            freq[ch - '0'] ++;
        }

        for (int i = 0; i < n - 1; i ++) {
            int first  = s[i] - '0';
            int second = s[i + 1] - '0';
            string res;
            if (first != second && freq[first] == first && freq[second] == second) {
                return res + to_string(first) + to_string(second);
            }
        }
        return "";
    }
};
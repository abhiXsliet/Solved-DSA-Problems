// https://leetcode.com/problems/make-the-string-great/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    string makeGood(string s) {
        int n = s.length();
        int i = 0;
        while(i < n-1) {
            if (abs(s[i] - s[i + 1]) == 32) {
                s.erase(i, 2);
                i = max(0, i - 1);
            } else {
                i ++;
            }
        }
        return s;
    }
};

// https://leetcode.com/problems/delete-characters-to-make-fancy-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    string makeFancyString(string s) {
        string result;
        int cnt = 1;
        for (int i = 0; i < s.length(); i ++) {
            result.push_back(s[i]);
            if (i > 0 && s[i] == s[i - 1]) {
                cnt += 1;
                if (cnt >= 3) {
                    result.pop_back();
                }
            } else {
                cnt = 1;
            }
        }
        return result;
    }
};
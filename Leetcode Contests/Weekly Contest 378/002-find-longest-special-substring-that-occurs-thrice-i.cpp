// https://leetcode.com/contest/weekly-contest-378/problems/find-longest-special-substring-that-occurs-thrice-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int res = -1;
        for (int len = 1; len <= n; len++) {
            unordered_map<string, int> count;
            for (int i = 0; i <= n - len; i++) {
                string sub = s.substr(i, len);
                if (sub.find_first_not_of(sub[0]) == string::npos) {
                    count[sub]++;
                    if (count[sub] >= 3) {
                        res = max(res, len);
                    }
                }
            }
        }
        return res;
    }
};

// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    string robotWithString(string s) {
        int n = s.length();

        vector<char> minCharToRight(n, s[n - 1]);
        for (int i = n - 2; i >= 0; i --) {
            minCharToRight[i] = min(s[i], minCharToRight[i + 1]);
        }

        string paper;
        string t;
        for (int i = 0; i < n; i ++) {
            t += s[i];

            char minChar = (i + 1 < n) ? minCharToRight[i + 1] : s[i];

            while (!t.empty() && t.back() <= minChar) {
                paper += t.back();
                t.pop_back();
            }
        }
        while (!t.empty()) {
            paper += t.back();
            t.pop_back();
        }
        return paper;
    }
};
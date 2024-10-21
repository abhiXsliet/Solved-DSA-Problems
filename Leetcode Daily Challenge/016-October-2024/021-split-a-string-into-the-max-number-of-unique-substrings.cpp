// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_set<string> st;

    // TC : O(2^N) Where N is the length of the string s
    // SC : O(N)   Space Used by Unordered Set
    int solve(string s, int idx) {
        if (idx >= s.length()) return 0;

        string pref;
        int ans = 0;
        for (int i = idx; i < s.length(); i ++) {
            pref += s[i];
            if (!st.count(pref)) {
                st.insert(pref);
                ans = max(ans, 1 + solve(s, i + 1));
                st.erase(pref);
            }
        }

        return ans;
    }
public:
    int maxUniqueSplit(string s) {
        return solve(s, 0);
    }
};
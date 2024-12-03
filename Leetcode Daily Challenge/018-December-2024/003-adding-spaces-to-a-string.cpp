// https://leetcode.com/problems/adding-spaces-to-a-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N) Where N = string 's' length
    // SC : O(M) Where M = spaces size
    string brute(string s, vector<int>& spaces) {
        unordered_set<int> st(begin(spaces), end(spaces));
        string res;
        int idx = 0;
        while (idx < s.length()) {
            if (st.count(idx)) 
                res += ' ';
            res += s[idx ++];
        }
        return res;
    }

    // TC : O(N)
    // SC : O(1)
    string optimal(string s, vector<int>& spaces) {
        int n = s.length(), m = spaces.size();
        int j = 0;
        string res;
        for (int i = 0; i < n; i ++) {
            if (j < m && i == spaces[j]) {
                res += ' ';
                j ++;
            }
            res += s[i];
        }
        return res;
    }
public:
    string addSpaces(string s, vector<int>& spaces) {
        // return brute(s, spaces);

        return optimal(s, spaces);
    }
};
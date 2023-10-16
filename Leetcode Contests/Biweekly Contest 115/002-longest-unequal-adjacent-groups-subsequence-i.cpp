// https://leetcode.com/contest/biweekly-contest-115/problems/longest-unequal-adjacent-groups-subsequence-i/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> res;
        res.push_back(words[0]);
        for (int i = 1; i < n; ++i) {
            if (groups[i] != groups[i - 1]) {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};
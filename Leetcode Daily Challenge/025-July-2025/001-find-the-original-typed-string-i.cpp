// https://leetcode.com/problems/find-the-original-typed-string-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int approach_1(string &word) {
        int n = word.length();
        int ans = 1;
        for (int i = 1; i < n; i ++) {
            if (word[i] == word[i - 1]) {
                ans += 1;
            }
        }
        return ans;
    }
public:
    int possibleStringCount(string word) {
        return approach_1(word);
    }
};
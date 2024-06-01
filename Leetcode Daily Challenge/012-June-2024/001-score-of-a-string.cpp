// https://leetcode.com/problems/score-of-a-string/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            score += abs(s[i] - s[i+1]);
        }
        return score;
    }
};
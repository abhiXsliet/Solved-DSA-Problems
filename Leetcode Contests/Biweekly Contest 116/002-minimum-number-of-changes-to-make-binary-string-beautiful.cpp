// https://leetcode.com/contest/biweekly-contest-116/problems/minimum-number-of-changes-to-make-binary-string-beautiful/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; i+=2) {
            if (s[i] != s[i + 1]) 
                cnt++;
        }
        return cnt;
    }
};
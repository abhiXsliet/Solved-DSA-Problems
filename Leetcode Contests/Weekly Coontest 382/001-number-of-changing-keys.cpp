// https://leetcode.com/contest/weekly-contest-382/problems/number-of-changing-keys/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKeyChanges(string s) {
        int changes = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (tolower(s[i]) != tolower(s[i-1])) {
                ++changes;
            }
        }
        return changes;

    }
};
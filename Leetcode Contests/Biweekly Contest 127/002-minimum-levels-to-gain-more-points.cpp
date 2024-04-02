// https://leetcode.com/contest/biweekly-contest-127/problems/minimum-levels-to-gain-more-points/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        
        for (int i = 0; i < n; i++) {
            if (possible[i] == 0) {
                possible[i] = -1;
            }
        }

        int bobPt    = accumulate(begin(possible), end(possible), 0);
        int danielPt = 0;

        for (int i = 0; i < n-1; i++) {
            danielPt += possible[i];
            bobPt    -= possible[i];

            if (danielPt > bobPt) {
                return i + 1;
            }
        }
        return -1;
    }
};
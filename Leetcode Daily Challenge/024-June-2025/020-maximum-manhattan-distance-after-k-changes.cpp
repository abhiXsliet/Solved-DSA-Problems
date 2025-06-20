// https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int maxDistance(string s, int k) {
        int n = s.length();

        int cntN = 0, cntS = 0, cntE = 0, cntW = 0;
        int maxD = INT_MIN;

        for (int i = 0; i < n; i ++) {
            if (s[i] == 'N') cntN += 1;
            else if (s[i] == 'S') cntS += 1;
            else if (s[i] == 'W') cntW += 1;
            else cntE += 1;

            int stepsTillNow = (i + 1);
            int actualDist   = abs(cntE - cntW) + abs(cntN - cntS);
            int wastedDist   = stepsTillNow - actualDist;

            int extraDist = 0;
            if (actualDist != stepsTillNow) {
                extraDist = min(2*k, wastedDist);
            }

            maxD = max(maxD, actualDist + extraDist);
        }

        return maxD;
    }
};
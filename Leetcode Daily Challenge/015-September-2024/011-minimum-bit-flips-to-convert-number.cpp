// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(max(log(start), log(goal)))
    int approach_1(int start, int goal) {
        int res = 0;
        while (start || goal) {
            int rem1 = start % 2;
            int rem2 = goal  % 2;

            if (rem1 != rem2) res ++;

            start /= 2;
            goal  /= 2;
        }
        return res;
    }

    // TC : O(log(xored))
    int approach_2(int start, int goal) {
        int res   = 0;
        int xored = start ^ goal;
        while (xored) {
            res += (xored & 1);
            xored >>= 1;
        }
        return res;
    }

    // TC : O(log(xored))
    int approach_3(int start, int goal) {
        int res   = 0;
        int xored = start ^ goal;
        while (xored) {
            xored &= (xored - 1);
            res += 1;
        }
        return res;
    }
public:
    int minBitFlips(int start, int goal) {
        // return approach_1(start, goal);

        // return approach_2(start, goal);

        return approach_3(start, goal); // Brian Kernighan's Aglo.
    }
};
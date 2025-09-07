// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;

    // TC : O(1)
    // SC : O(1)
    int makeTheIntegerZero(int num1, int num2) {
        int t = 0;  // it depicts the min opr

        while (true) {     // this work at max 35 times
            ll val = ((ll)num1 - ((ll)t * num2));

            if (val < 0) return -1;

            if (__builtin_popcountll(val) <= t && t <= val) {
                return t;
            }

            t ++;
        }

        return -1;  // code flow didn't reach here
    }
};
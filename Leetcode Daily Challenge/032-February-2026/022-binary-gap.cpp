// https://leetcode.com/problems/binary-gap/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int maxD = 0;
        for (int i = 0; i < 32; i ++) {
            if (n & (1 << i)) {
                if (prev == -1) prev = i;
                else {
                    maxD = max(maxD, abs(i - prev));
                    prev = i;
                }
            }
        }
        return maxD;
    }
};
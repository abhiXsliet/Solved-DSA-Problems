// https://leetcode.com/problems/binary-number-with-alternating-bits/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    // TC : O(log(N))
    // SC : O(1)
    bool approach_1(int n) {
        int totalBits = (n == 0) ? 1 : floor(log2(n)) + 1;
        bool flag = (n & 1);
        for (int i = 1; i < totalBits; i ++) {
            bool newFlag = (n & (1 << i));
            if (flag == newFlag) {
                return false;
            }
            flag = newFlag;
        }
        return true;
    }

    // TC : O(1)
    // SC : O(1)
    bool approach_2(int n) {
        unsigned int result = n ^ (n >> 1);

        return (result & (result + 1)) == 0;
    }
public:
    bool hasAlternatingBits(int n) {
        // return approach_1(n);
        return approach_2(n);
    }
};
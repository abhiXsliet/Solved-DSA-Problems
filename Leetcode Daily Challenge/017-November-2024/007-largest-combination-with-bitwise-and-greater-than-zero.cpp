// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int largestCombination(vector<int>& candidates) {
        int maxCombnSize = 0;
        for (int b = 0; b < 24; b ++) {
            int count = 0;
            for (int num : candidates) {
                if (num & (1 << b))
                    count ++;
            }
            maxCombnSize = max(maxCombnSize, count);
        }
        return maxCombnSize;
    }
};
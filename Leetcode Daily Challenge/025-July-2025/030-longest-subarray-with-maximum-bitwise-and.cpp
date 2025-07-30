// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int longestSubarray(vector<int>& nums) {
        int maxi = 0, maxLen = 0, seqLen = 0;
        for (int num : nums) {
            if (num > maxi) {
                maxi = num;
                seqLen = 0;
                maxLen = 0;
            }

            seqLen = (num == maxi) ? seqLen + 1 : 0;

            maxLen = max(maxLen, seqLen);
        }
        return maxLen;
    }
};
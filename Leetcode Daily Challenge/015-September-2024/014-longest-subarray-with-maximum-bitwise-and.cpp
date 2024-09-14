// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        int result = 0;
        int streak = 0;
        int maxVal = 0;

        while (i < n) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                streak = 0;
                result = 0;
            }

            if (nums[i] == maxVal) {
                streak ++;
            } else {
                streak = 0;
            }
            i ++;
            result = max(result, streak);
        }
        return result;
    }
};
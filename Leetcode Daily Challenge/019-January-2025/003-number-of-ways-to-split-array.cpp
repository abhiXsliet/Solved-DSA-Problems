// https://leetcode.com/problems/number-of-ways-to-split-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long total = accumulate(begin(nums), end(nums), 0LL);
        int cntValid = 0;
        long currSum = 0;
        for (int i = 0; i < n - 1; i ++) {
            currSum += nums[i];
            long rem  = total - currSum;
            if (currSum >= rem) cntValid ++;
        }
        return cntValid;
    }
};
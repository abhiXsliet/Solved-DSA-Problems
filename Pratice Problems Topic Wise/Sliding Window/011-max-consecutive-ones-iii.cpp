// https://leetcode.com/problems/max-consecutive-ones-iii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0, cntZero = 0;
        int maxLen = 0;

        while (j < n) {
            if (nums[j] == 0) 
                cntZero ++;

            while (cntZero > k) {
                if (nums[i] == 0) 
                    cntZero --;
                i ++;
            }

            if (cntZero <= k) {
                maxLen = max(maxLen, j - i + 1);
            }

            j ++;
        }
        return maxLen;
    }
};
// https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);

        // setBitIdx[j] = i, tells that jth bit can be set via element at index i in nums
        vector<int> setBitIdx(32, -1);

        for (int i = n - 1; i >= 0; i --) {
            
            int endIdx = i;
            for (int j = 0; j < 32; j ++) {
                if (!(nums[i] & (1 << j))) {
                    if (setBitIdx[j] != -1) {
                        endIdx = max(endIdx, setBitIdx[j]);
                    }
                } else {
                    setBitIdx[j] = i;
                }
            }

            result[i] = (endIdx - i + 1);
        }

        return result;
    }
};
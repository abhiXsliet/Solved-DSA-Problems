// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = *max_element(begin(nums), end(nums));
        int i = 0, j = 0, cntMaxi = 0;
        long long cntSubArray = 0;

        while(j < n) {
            if (nums[j] == maxi) {
                cntMaxi ++;
            }
            while (cntMaxi >= k) {
                cntSubArray += n - j;
                if (nums[i] == maxi) {
                    cntMaxi --;
                }
                i++;
            }
            j ++;
        }
        return cntSubArray;
    }
};
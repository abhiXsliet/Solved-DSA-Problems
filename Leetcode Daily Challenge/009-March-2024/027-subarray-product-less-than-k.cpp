// https://leetcode.com/problems/subarray-product-less-than-k/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Tc : O(N)
    // SC : O(1)
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        if (k <= 1) return 0;

        int cntSubarray = 0;
        int product     = 1;

        int i = 0, j = 0;
        while (j < n) {
            product *= nums[j];

            while(product >= k) {
                product /= nums[i];
                i ++;
            }
            cntSubarray += j - i + 1;
            j ++;
        }
        return cntSubarray;
    }
};
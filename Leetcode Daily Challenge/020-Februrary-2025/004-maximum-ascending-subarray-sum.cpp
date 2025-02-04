// https://leetcode.com/problems/maximum-ascending-subarray-sum/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int sum = nums[0];
        for (int i = 1; i < n; i ++) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i];
                maxSum = max(maxSum, sum);
            } else {
                sum = nums[i];
            }
        }
        return maxSum;
    }
};
// https://leetcode.com/problems/maximum-erasure-value/?envType=daily-question&envId=2025-07-22




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int i = 0, j = 0, maxSum = 0, sum = 0;
        while (j < n) {
            mpp[nums[j]] ++;
            sum += nums[j];
            while (mpp[nums[j]] > 1) {
                mpp[nums[i]] --;
                sum -= nums[i];
                i ++;
            }
            maxSum = max(maxSum, sum);
            j ++;
        }
        return maxSum;
    }
};
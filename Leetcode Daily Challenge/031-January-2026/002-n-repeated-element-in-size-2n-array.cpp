// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i ++) {
            if (nums[i] == nums[i - 1] || (i >= 2 && nums[i] == nums[i - 2]) || (i >= 3 && nums[i] == nums[i - 3])) {
                return nums[i];
            }
        }
        return -1;
    }
};
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;
        int twoSum = 0;
        while (i < j) {
            twoSum = nums[i] + nums[j];
            if (twoSum == target) {
                return {i + 1, j + 1};
            }
            if (twoSum > target) j --;
            else i ++;
        }
        return {};
    }
};
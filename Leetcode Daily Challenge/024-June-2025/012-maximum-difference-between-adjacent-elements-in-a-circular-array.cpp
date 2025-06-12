// https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxD = INT_MIN;
        for (int i = 0; i < n; i ++) {
            maxD = max(maxD, abs(nums[i] - nums[(i + 1) % n]));
        }
        return maxD;
    }
};
// https://leetcode.com/problems/type-of-triangle/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string brute(vector<int> &nums) {
        if (nums[0] + nums[1] > nums[2] && nums[1] + nums[2] > nums[0] && nums[0] + nums[2] > nums[1]) {
            if (nums[0] == nums[1] && nums[1] == nums[2] && nums[0] == nums[2])
                return "equilateral";
            else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2])
                return "isosceles";
            else
                return "scalene";
        }
        return "none";
    }
public:
    // TC : O(1)
    // SC : O(1)
    string triangleType(vector<int>& nums) {
        return brute(nums);
    }
};
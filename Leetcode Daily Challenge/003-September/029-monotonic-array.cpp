// https://leetcode.com/problems/monotonic-array/


#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    bool solve(vector<int>& nums) {
        int n = nums.size();

        bool increasing = 0, decreasing = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] < nums[i])
                decreasing = true;
            
            if (nums[i + 1] > nums[i])
                increasing = true;
        }

        if (increasing == true && decreasing == true)
            return false;
        else return true;
    }
public:
    bool isMonotonic(vector<int>& nums) {
        return solve(nums);
    }
};
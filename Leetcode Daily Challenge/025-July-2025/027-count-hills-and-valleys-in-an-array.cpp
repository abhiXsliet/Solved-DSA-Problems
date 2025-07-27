// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int countHillValley(vector<int>& nums) {
        int n = nums.size();

        int i = 1, ans = 0;
        while (i < n - 1) {
            int prev = nums[i - 1];
            while (i < n - 1 && nums[i] == nums[i + 1]) i ++;
    
            if (i < n - 1 && ((prev < nums[i] && nums[i] > nums[i + 1]) ||    // Valley
                             (prev > nums[i] && nums[i] < nums[i + 1]))) {    // Hill
                ans += 1;
            }
            i ++;
        }
        return ans;
    }
};
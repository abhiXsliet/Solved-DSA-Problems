// https://leetcode.com/problems/maximum-width-ramp/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxSuffix(n, nums[n - 1]);
        for (int i = n - 2; i >= 0; i --) {
            maxSuffix[i] = max(nums[i], maxSuffix[i + 1]);
        }

        int i = 0, j = 0, maxRampWdth = 0;

        while (j < n) {
            while (i < j && nums[i] > maxSuffix[j]) {
                i ++;
            }

            maxRampWdth = max(maxRampWdth, j - i);
            j ++;
        }

        return maxRampWdth;
    }
public:
    int maxWidthRamp(vector<int>& nums) {
        return approach_1(nums);    // store max to the right

        // return approach_2(nums);    // Pending -> Monotonic Stack??
    }
};
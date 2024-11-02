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

    // TC : O(N) Visiting every element only twice
    // SC : O(N) Storing all elements
    int approach_2(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk; // store the indices of nums[i]
        for (int i = 0; i < n; i ++) {
            if (stk.empty() || nums[i] <= nums[stk.top()]) {
                stk.push(i);
            }
        }

        int maxRampWidth = 0;
        for (int j = n - 1; j >= 0; j --) {
            while (!stk.empty() && nums[stk.top()] <= nums[j]) {
                int i = stk.top();
                stk.pop();
                maxRampWidth = max(maxRampWidth, j - i);
            }
        }
        return maxRampWidth;
    }
public:
    int maxWidthRamp(vector<int>& nums) {
        // return approach_1(nums);    // store max to the right

        return approach_2(nums);    // Monotonic Stack
    }
};
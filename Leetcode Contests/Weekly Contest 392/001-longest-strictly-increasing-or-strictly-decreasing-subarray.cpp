// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    int solve_brute(vector<int>& nums, int n) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int len1 = 1, len2 = 1;
            int nums_j = nums[i];
            for (int k = i + 1; k < n; k++) {
                if (nums[k] > nums_j) {
                    len1 ++;
                    nums_j = nums[k];
                }
                else break;
            }
            nums_j = nums[i];
            for (int k = i + 1; k < n; k++) {
                if (nums[k] < nums_j) {
                    len2 ++;
                    nums_j = nums[k];
                }
                else break;
            }
            ans = max(ans, max(len1, len2));
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(1)
    int solve_optimal(vector<int>& nums, int n) {
        int inc = 1, dec = 1, ans = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc ++;
                dec = 1;
            }
            else if (nums[i] < nums[i - 1]) {
                dec ++;
                inc = 1;
            }
            else {
                inc = 1;
                dec = 1;
            }
            ans = max({ans, inc, dec});
        }
        return ans;
    }
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // return solve_brute(nums, nums.size());

        return solve_optimal(nums, nums.size());
    }
};
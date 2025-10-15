// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isInc(vector<int>&nums, int n, int start, int end) {
        for (int i = start + 1; i < end && i <= n; i ++) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        return true;
    }

    // TC : O(N^2)
    // SC : O(1)
    bool brute(vector<int> &nums, int k) {
        int n = nums.size();
        for (int i = 0; i + 2*k <= n; i ++) {
            if (isInc(nums, n, i, i + k) && isInc(nums, n, i + k, i + k + k)) {
                return true;
            }
        }
        return false;
    }

    // TC : O(N)
    // SC : O(1)
    bool optimal(vector<int> &nums, int k) {
        int n = nums.size();

        int prevInc = 0, currInc = 1;
        for (int i = 1; i < n; i ++) {
            if (nums[i] > nums[i - 1]) {
                currInc += 1;
            } else {
                prevInc = currInc;
                currInc = 1;
            }

            if (currInc / 2 >= k || min(currInc, prevInc) >= k) {
                return true;
            }
        }
        return false;
    }
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        // return brute(nums, k);
        return optimal(nums, k);
    }
};
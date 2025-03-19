// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void flipElements(vector<int> &nums, int n, int start, int end) {
        for (int i = start; i <= end && i < n; i ++) {
            nums[i] = (1 - nums[i]);
        }
    }

    // TC : O(N)
    // SC : O(1)
    int approach_1(vector<int> &nums) {
        int n = nums.size();

        int operations = 0;
        for (int i = 0; i < n - 2; i ++) {
            if (nums[i]) continue;

            flipElements(nums, n, i, i + 2);
            operations += 1;
        }
        return (!nums[n - 1] || !nums[n - 2]) ? -1 : operations;
    }
public:
    int minOperations(vector<int>& nums) {
        return approach_1(nums);    // simulation
    }
};
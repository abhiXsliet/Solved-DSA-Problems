// https://leetcode.com/problems/maximum-difference-between-increasing-elements/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    int approach_1(vector<int> &nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                if (nums[j] > nums[i]) {
                    ans = max(ans, nums[j] - nums[i]);
                }
            }
        }
        return ans == INT_MIN ? -1 : ans;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int> &nums) {
        int n = nums.size();
        vector<int> mini(n, nums[0]);
        for (int i = 1; i < n; i++) {
            mini[i] = min(nums[i], mini[i - 1]);
        }
        int ans = INT_MIN;
        for (int i = 1; i < n; i ++) {
            if (nums[i] > mini[i - 1]) {
                ans = max(ans, nums[i] - mini[i - 1]);
            }
        }
        return (ans == INT_MIN) ? -1 : ans;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_3(vector<int> &nums) {
        int n = nums.size();
        int mini = nums[0];
        int ans = INT_MIN;
        for (int i = 1; i < n; i ++) {
            if (nums[i] > mini) {
                ans = max(ans, nums[i] - mini);
            }
            mini = min(mini, nums[i]);
        }
        return (ans == INT_MIN) ? -1 : ans;
    }
public:
    int maximumDifference(vector<int>& nums) {
        // return approach_1(nums);
        // return approach_2(nums);
        return approach_3(nums);
    }
};
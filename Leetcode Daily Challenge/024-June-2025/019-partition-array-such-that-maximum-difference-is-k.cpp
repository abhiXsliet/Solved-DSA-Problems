// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N * log(N))
    // SC : O(1)
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int mini = nums[0];
        int cnt  = 1;
        for (int i = 0; i < n; i ++) {
            if (nums[i] - mini > k) {
                mini = nums[i];
                cnt += 1;
            }
        }
        return cnt;
    }
};
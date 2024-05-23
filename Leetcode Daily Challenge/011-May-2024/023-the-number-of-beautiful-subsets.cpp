// https://leetcode.com/problems/the-number-of-beautiful-subsets/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int result;
    // TC : O(2^N)
    // SC : O(N)
    void solve(vector<int>& nums, int k, unordered_map<int, int>& mpp, int idx) {
        if (idx == nums.size()) {
            result ++;
            return;
        }

        solve(nums, k, mpp, idx + 1);
        
        if (!mpp[nums[idx] - k] && !mpp[nums[idx] + k]) {
            mpp[nums[idx]] ++;
            solve(nums, k, mpp, idx + 1);
            mpp[nums[idx]] --;
        }
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        result = 0;
        unordered_map<int, int> mpp;
        solve(nums, k, mpp, 0);
        return result - 1;
    }
};
// https://leetcode.com/problems/longest-harmonious-subsequence/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * log(N))
    // SC : O(1)
    int approach_1(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int i = 0, j = 1, len = 0;
        while (j < n) {
            while (i < j && (nums[j] - nums[i] > 1))
                i ++;
            if (nums[j] - nums[i] == 1) {
                len = max(len, j - i + 1);
            }
            j ++;
        }
        return len;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int &num : nums) {
            mpp[num] ++;
        }

        int len = 0;
        for (int &num : nums) {
            if (mpp.count(num + 1)) {
                len = max(len, mpp[num] + mpp[num + 1]);
            }
        }
        return len;
    }
public:
    int findLHS(vector<int>& nums) {
        // return approach_1(nums);
        return approach_2(nums);
    }
};
// https://leetcode.com/problems/set-mismatch/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    vector<int> solve_approach_1(vector<int>& nums, int n) {
        unordered_map<int, int> mpp;
        vector<int> result;

        for (int num : nums) mpp[num] ++;

        for (auto& it : mpp) {
            if (mpp[it.first] >= 2)
                result.push_back(it.first);
        }
        for (int i = 1; i <= n; i++) {
            if (mpp.find(i) == mpp.end()) {
                result.push_back(i);
            }
        }
        return result;
    }

    // TC : O(N)
    // SC : O(1)
    vector<int> solve_approach_2(vector<int>& nums, int n) {
        int duplicate = -1;
        int missing   = -1;

        for (int i = 0; i < n; i++) {
            if (nums[abs(nums[i]) - 1] < 0) {
                duplicate = abs(nums[i]);
            }else {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }

        return {duplicate, missing};
    }
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // return solve_approach_1(nums, nums.size());

        return solve_approach_2(nums, nums.size());
    }
};
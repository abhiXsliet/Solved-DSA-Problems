// https://leetcode.com/problems/binary-subarrays-with-sum/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int solve_1(vector<int>& nums, int goal) {
        unordered_map<int, int> mpp;

        mpp[0] = 1;

        int result   = 0;
        int cumm_sum = 0;

        for (int& num : nums) {
            cumm_sum += num;

            int rem_sum = cumm_sum - goal;
            if (mpp.find(rem_sum) != mpp.end()) {
                result += mpp[rem_sum];
            }

            mpp[cumm_sum] ++;
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N)
    int solve_2(vector<int>& nums, int goal) {
        int n = nums.size();
        
        int i = 0, j = 0;
        int result  = 0;
        int prefZer = 0; // prefix zeros
        int windSum = 0;

        while(j < n) {
            windSum += nums[j];
            while (i < j && (nums[i] == 0 || windSum > goal)) {
                if (nums[i] == 0) prefZer ++;
                else prefZer = 0;

                windSum -= nums[i];
                i++;
            }
            if (windSum == goal) {
                result += 1 + prefZer;
            }
            j++;
        }
        return result;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // return solve_1(nums, goal);

        return solve_2(nums, goal);
    }
};
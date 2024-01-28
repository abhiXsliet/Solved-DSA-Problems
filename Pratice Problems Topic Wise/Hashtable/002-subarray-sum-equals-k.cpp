// https://leetcode.com/problems/subarray-sum-equals-k/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^3)
    // SC : O(1)
    int solve_brute(vector<int>& nums, int n, int k) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                if (sum == k) ans++;
            }
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(N)
    int solve_optimal(vector<int>& nums, int n, int k) {
        int ans = 0;
        
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int cummulative_sum = 0;
        
        for (int num : nums) {
            
            cummulative_sum += num;

            if (mpp.find(cummulative_sum - k) != mpp.end()) {
                ans += mpp[cummulative_sum - k];
            }
            mpp[cummulative_sum]++;
        }
        return ans;
    }
public:
    int subarraySum(vector<int>& nums, int k) {
        // return solve_brute(nums, nums.size(), k);

        return solve_optimal(nums, nums.size(), k);
    }
};
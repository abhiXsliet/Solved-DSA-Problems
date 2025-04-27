// https://leetcode.com/problems/count-of-interesting-subarrays/

// prerequisite : https://leetcode.com/problems/subarray-sums-divisible-by-k/description/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        int n = nums.size();
        
        long long cntSubArr = 0;
        int cumm_sum = 0;
        unordered_map<int, int> mpp;
        mpp[cumm_sum] = 1;

        for (int &num : nums) {
            cumm_sum += (num % mod == k) ? 1 : 0; 

            int r1 = (cumm_sum % mod);
            int r2 = (r1 - k + mod) % mod;

            cntSubArr += mpp[r2];

            mpp[r1] += 1;
        }

        return cntSubArr;
    }
};
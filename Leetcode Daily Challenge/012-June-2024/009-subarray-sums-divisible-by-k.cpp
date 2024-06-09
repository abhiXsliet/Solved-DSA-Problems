// https://leetcode.com/problems/subarray-sums-divisible-by-k/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    int better(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 1; i < n; i ++) {
            nums[i] += nums[i - 1];
        }

        int cntSubarray = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j ++) {
                int sum = (i == 0) ? nums[j] : nums[j] - nums[i - 1];
                if (sum % k == 0) {
                    cntSubarray += 1;
                } 
            }
        }
        return cntSubarray;
    }

    // TC : O(N)
    int optimal(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mpp;
        int cumm_sum  = 0;
        mpp[cumm_sum] = 1;

        int cntSubarray = 0;
        for (int i = 0; i < n; i ++) {
            cumm_sum += nums[i];

            int rem = cumm_sum % k;
            if (rem < 0) rem += k;      // catch: to make the remainder positive
            
            cntSubarray += mpp[rem];    // add cnt of subarray to answer
            mpp[rem] ++;
        }
        return cntSubarray;
    }
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Brute : use three loops & cal
        
        // return better(nums, k);

        return optimal(nums, k);
    }
};
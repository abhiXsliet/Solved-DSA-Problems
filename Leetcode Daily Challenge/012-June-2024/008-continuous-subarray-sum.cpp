// https://leetcode.com/problems/continuous-subarray-sum/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^3)
    // SC : O(1)
    bool brute(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i ++) {
            for (int j = i + 1; j < n; j ++) {

                int sum = 0;
                for (int k = i; k <= j; k ++) {
                    sum += nums[k];
                }

                if (sum % k == 0) {
                    return true;
                }
            }   
        }

        return false;
    }

    // TC : O(N^2)
    // SC : O(1)
    bool better(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i ++) {
            int sum = nums[i];
            for (int j = i + 1; j < n; j ++) {
                sum += nums[j];
                
                if (sum % k == 0) {
                    return true;
                }
            }   
        }

        return false;
    }

    // TC : O(N)
    // SC : O(N)
    bool optimal(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mpp;    // {sum%k, index}
       
        mpp[0]  = -1;
        int sum = 0;

        for (int i = 0; i < n; i ++) {
            sum    += nums[i];
            int rem = sum % k;

            if (mpp.count(rem)) {
                if (i - mpp[rem] >= 2)  // subarray size should be at least 2 
                    return true;
            } else mpp[rem] = i;
        }

        return false;
    }
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // return brute(nums, k);

        // return better(nums, k);

        return optimal(nums, k);
    }
};
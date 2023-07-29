// https://leetcode.com/problems/maximum-subarray/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int maxSumCenter(vector<int>& nums, int l, int mid, int h) {
        int left_sum = INT_MIN;
        int sum = 0;
        for(int i = mid; i >= l; i--) {
            sum += nums[i];
            if(sum > left_sum) left_sum = sum;
        }

        int right_sum = INT_MIN;
        sum = 0;
        for(int i = mid; i <= h; i++) {
            sum += nums[i];
            if(sum > right_sum) right_sum = sum;
        }

        return max( left_sum + right_sum - nums[mid], max(left_sum, right_sum) );
    }

    int maxSumSubArray(vector<int>& nums, int l, int h) {
        if(l > h) return INT_MIN;
        if(l == h) return nums[l];

        int mid = l + (h - l)/2;
        return max( max(maxSumSubArray(nums, l, mid-1), 
                    maxSumSubArray(nums, mid+1, h)), 
                    maxSumCenter(nums, l, mid, h) );
    }

    int kadane_Algo(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum > maxi) maxi = max(maxi, sum);
            if(sum < 0) sum = 0;
        }
        return maxi; 
    }
public:
    int maxSubArray(vector<int>& nums) {
        // TC = O(N)
        // return kadane_Algo(nums);

        // TC = O(N * log(N))
        return maxSumSubArray(nums, 0, nums.size() - 1);
    }
};
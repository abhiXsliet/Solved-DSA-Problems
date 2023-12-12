// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N * log(N))
    int solve_brute(vector<int>& nums, int n) {
        int ans = 0;
        sort(begin(nums), end(nums));
        ans = (nums[n - 1] - 1) * (nums[n - 2] - 1);
        return ans;
    }

    // TC = O(N)
    int solve_better(vector<int>& nums, int n) {
        int largest = 0;
        int second_largest = 0;

        for (int i = 0; i < n; i++) {
            if (largest <= nums[i]) {
                second_largest = largest;
                largest        = nums[i];
            }
            else {
                second_largest = max(second_largest, nums[i]);
            }
        }

        return ((largest - 1) * (second_largest - 1));
    }

    // TC = O(N)
    int solve_optimal(vector<int>& nums, int n) {
        int curr_max = nums[0];
        int res = 0;
        for (int i = 1; i < n; i++) {
            res = max( res, ((curr_max - 1) * (nums[i] - 1)) );
            if (nums[i] > curr_max) 
                curr_max = nums[i];
        }
        return res;
    }
public:
    int maxProduct(vector<int>& nums) {
        // return solve_brute(nums, nums.size());

        // return solve_better(nums, nums.size());

        return solve_optimal(nums, nums.size());
    }
};
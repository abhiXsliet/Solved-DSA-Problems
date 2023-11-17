// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N * log(N))
    // SC = O(1)
    int solve(vector<int>& nums, int n) {
        // Step-1 : Sort the given array
        sort(begin(nums), end(nums));

        // Step-2 : Initialize the two pointers
        int i = 0;
        int j = n - 1;

        int result = INT_MIN;
        // Step-3 : Run two pointers
        while (i < j) {
            int sum = nums[i] + nums[j];
            result = max(result, sum);
            i++;
            j--;
        }

        return result;
    }
public:
    int minPairSum(vector<int>& nums) {
        return solve(nums, nums.size());
    }
};
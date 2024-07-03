// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(1)
    int approach_1(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        if (n > 3) {
            int result = INT_MAX;
            result = min(result, nums[n - 4] - nums[0]);
            result = min(result, nums[n - 3] - nums[1]);
            result = min(result, nums[n - 2] - nums[2]);
            result = min(result, nums[n - 1] - nums[3]);
            return result;
        } 
        return 0;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int>& nums) {
        int n = nums.size();

        if (n <= 3) return 0;

        partial_sort(begin(nums), begin(nums) + 4, end(nums));  // O(Nlog(4)) ~= O(N)

        /* Explanation:
         - We want to find the element that would be at the position (n - 4) if the array were sorted.
         - This element will be placed at the position (n - 4) in the array.
         - All elements less than this element will be to its left.
         - All elements greater than this element will be to its right.
        */
        nth_element(begin(nums) + 4, begin(nums) + (n - 4), end(nums)); // O(N)

        sort(begin(nums) + (n - 4), end(nums));

        int result = INT_MAX;
        result = min(result, nums[n - 4] - nums[0]);
        result = min(result, nums[n - 3] - nums[1]);
        result = min(result, nums[n - 2] - nums[2]);
        result = min(result, nums[n - 1] - nums[3]);
        return result;
    }
public:
    int minDifference(vector<int>& nums) {
        // return approach_1(nums);    // SORTING

        return approach_2(nums);
    }
};
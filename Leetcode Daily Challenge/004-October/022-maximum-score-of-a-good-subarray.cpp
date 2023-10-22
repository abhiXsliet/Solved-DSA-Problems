// https://leetcode.com/problems/maximum-score-of-a-good-subarray/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N)
    // SC = O(1)
    int solve_greedy(vector<int>& nums, int k) {
        int n = nums.size();

        int i = k;
        int j = k;
        int currMin = nums[k];
        int result  = nums[k];

        while (i > 0 || j < n-1) {

            int leftValue  = (i  >  0) ? nums[i-1] : 0;
            int rightValue = (j < n-1) ? nums[j+1] : 0;

            if (leftValue > rightValue) {
                i--;
                currMin = min(currMin, nums[i]);
            }
            else {
                j++;
                currMin = min(currMin, nums[j]);
            }

            result = max(result, currMin * (j - i + 1));
        }

        return result;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        return solve_greedy(nums, k);
    }
};
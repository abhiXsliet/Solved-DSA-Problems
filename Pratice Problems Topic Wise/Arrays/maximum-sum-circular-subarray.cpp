// https://leetcode.com/problems/maximum-sum-circular-subarray/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N^3)
    // SC = O(1)
    int solve_brute(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < i + n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += nums[(k + 1) % n];
                    maxSum = max(maxSum, sum);
                }
            }
        }
        return maxSum;
    }

    // TC = O(N^2)
    // SC = O(1)
    int solve_better(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < i + n; j++) {
                sum += nums[(j + 1) % n];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }

    // TC = O(N)
    // SC = O(1)
    int solve_optimal(vector<int>& nums) {
        int total = 0;

        int maxSum = INT_MIN, curMax = 0;
        int minSum = INT_MAX, curMin = 0;
        
        for (int& num : nums) {
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);

            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
            
            total += num;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }

public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // return solve_brute(nums);

        // return solve_better(nums);

        return solve_optimal(nums);
    }
};
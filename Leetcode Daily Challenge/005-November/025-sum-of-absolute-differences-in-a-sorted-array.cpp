// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N * N) -> TLE
    // SC = O(1)
    vector<int> solve_brute(vector<int>& nums, int n) {
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if(i != j)
                    sum += abs(nums[j] - nums[i]);
            }
            result.push_back( sum );
        }
        return result;
    }

    // TC = O(N)
    // SC = O(N)
    vector<int> solve_better(vector<int>& nums, int n) {
        vector<int> result(n);
        vector<int> prefixSum (n);

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            // result[i] = (nums[i] * i) - (sum from 0 to i - 1 index) 
            //                           + (sum of index i+1 to n-1) - (nums[i] * (n-i-1))
            int leftSum  = prefixSum[i] - nums[i];
            int rightSum = prefixSum[n - 1] - prefixSum[i];

            result[i] = (nums[i] * i) - leftSum + rightSum - (nums[i] * (n - i - 1));
        }

        return result;
    }

    // TC = O(N)
    // SC = O(1)
    vector<int> solve_optimal(vector<int>& nums, int n) {
        vector<int> result(n);

        int sum = accumulate(begin(nums), end(nums), 0);
        // stores the prefixSum till (i - 1)th index
        int prefixSum = 0;

        for (int i = 0; i < n; i++) {

            int leftSum  = prefixSum;
            int rightSum = sum - prefixSum - nums[i];

            result[i] = (nums[i] * i) - leftSum + rightSum - (nums[i] * (n - i - 1));

            prefixSum += nums[i];
        }

        return result;
    }
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // return solve_brute(nums, nums.size());

        // return solve_better(nums, nums.size());

        return solve_optimal(nums, nums.size());
    }
};
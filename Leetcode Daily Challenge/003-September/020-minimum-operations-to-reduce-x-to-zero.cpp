// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/



#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    // TC = O(N)
    // SC = O(N)
    int solve_better(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mpp; // {sum, index}

        mpp[0] = -1;
        for (int i = 0; i < n; i++) {
            sum      += nums[i];
            mpp[sum]  = i;
        }

        if (sum < x) return -1;

        int remaining_sum = sum - x;
        int longest_subArray = INT_MIN;
        sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int findSum = sum - remaining_sum;
            
            if(mpp.find(findSum) != mpp.end()) {
                
                int idx = mpp[findSum];
                longest_subArray = max (longest_subArray, i - idx);
            }
        }

        return longest_subArray == INT_MIN ? -1 : n - longest_subArray;
    }

    // TC = O(N), SC = O(1)
    // Sliding Window Approach
    int solve_optimal(vector<int>& nums, int x) {
        int totalSum = 0;
        for (int& num : nums) 
            totalSum += num;

        int min_opr = INT_MAX;
        int n = nums.size();
        int left = 0, right = 0, curr = 0;

        while (right < n) {
            curr += nums[right];

            while (curr > totalSum - x && left <= right) {
                curr -= nums[left];
                left ++;
            }

            if (curr == totalSum - x) {
                min_opr = min(min_opr, n - (right - left + 1));
            }
            right ++;
        }
        return min_opr == INT_MAX ? -1 : min_opr;
    }
public:
    int minOperations(vector<int>& nums, int x) {

        return solve_better(nums, x);
        
        // return solve_optimal(nums, x);
    }
};

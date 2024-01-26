// https://leetcode.com/contest/biweekly-contest-122/problems/divide-an-array-into-subarrays-with-minimum-cost-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    int solve_brute(vector<int>& nums, int n) {
        int result = INT_MAX;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int res = 0;
                // first part
                for (int k = 0; k < i; k++) {
                    res += nums[k];
                    break;
                }
                // second part
                for (int k = i; k < j; k++) {
                    res += nums[k];
                    break;
                }
                // third part
                for (int k = j; k < n; k++) {
                    res += nums[k];
                    break;
                }
                result = min(result, res);
            }
        }
        return result;
    }
public:
    int minimumCost(vector<int>& nums) {
        return solve_brute(nums, nums.size());
    }
};

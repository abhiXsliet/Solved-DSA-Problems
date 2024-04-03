// https://leetcode.com/contest/biweekly-contest-127/problems/shortest-subarray-with-or-at-least-k-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^3)
    // SC : O(1)
    int solve_brute(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j ++) {
                int val = 0;
                for (int k = i; k <= j; k++) {
                    val |= nums[k];
                }
                if (val >= k) {
                    ans = min(ans, j - i + 1);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }

    // TC : O(N^2)
    // SC : O(1)
    int solve_better(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        int i = 0, j = 0;

        while (j < n) {
            int val = 0;
            for (int x = i; x <= j; x++) {
                val |= nums[x];
            }

            while (i < j && val >= k) {
                ans = min(ans, j - i + 1);
                i++;
                val = 0;
                for (int x = i; x <= j; x++) {
                    val |= nums[x];
                }
            }

            if (val >= k) {
                ans = min(ans, j - i + 1);
            }
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }

    // TC : O(1)
    // SC : O(1)
    int get_or_result(vector<int>& bitVec, vector<int>& nums, int i, int j, bool flag) {
        int val = 0;
        if (flag) {
            for (int b = 0; b < 32; b++) {
                bitVec[31 - b] += (nums[j] >> b) & 1 ;
            }
        }
        else {
            for (int b = 0; b < 32; b++) {
                bitVec[31 - b] -= (nums[i] >> b) & 1 ;
            }
        }
        for (int b = 31; b >= 0; b--) {
            val += (bitVec[b] > 1 ? 1 : bitVec[b]) * pow(2, 32-b-1);
        }
        return val;
    }

    // TC : O(N)
    // SC : O(1)
    int solve_optimal(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = INT_MAX;
        int i = 0, j = 0;
        vector<int> bitVec(32, 0);

        while (j < n) {
            int val = get_or_result(bitVec, nums, i, j, 1);
            
            while (i < j && val >= k) {
                ans = min(ans, j - i + 1);
                val = get_or_result(bitVec, nums, i, j, 0);
                i++;
            }
            if (val >= k) {
                ans = min(ans, j - i + 1);
            }
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        // return solve_brute(nums, k);

        // return solve_better(nums, k);

        return solve_optimal(nums, k);
    }
};
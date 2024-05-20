// https://leetcode.com/problems/sum-of-all-subset-xor-totals/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(2^N)
    // SC : O(N) -> Space Used by Recursive Stack
    int func(vector<int>& nums, int n, int i, int xorSum) {
        if (i == n) return xorSum;

        int incl = func(nums, n, i + 1, xorSum ^ nums[i]);
        int excl = func(nums, n, i + 1, xorSum);
        
        return incl + excl;
    }

    // TC : O(2^N * L)
    // SC : O(2^N * L)
    void solve(vector<int>& nums, int n, int i, vector<vector<int>>& allSubsets, vector<int>& currSubset) {
        if (i == n) {
            allSubsets.push_back(currSubset);
            return;
        }

        currSubset.push_back(nums[i]);
        solve(nums, n, i + 1, allSubsets, currSubset);
        currSubset.pop_back();
        solve(nums, n, i + 1, allSubsets, currSubset);
    }

    // TC : O(2^N * L)
    // SC : O(2^N * L) Where L = Average Length of subset
    int approach_1(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> allSubsets;
        vector<int> currSubsets;
        solve(nums, n, 0, allSubsets, currSubsets);

        int res = 0;
        for (vector<int>& subset : allSubsets) {
            int xorSum = 0;
            for (int& num : subset) {
                xorSum ^= num;
            }
            res += xorSum;
        }
        return res;
    }

    // TC : O(2^N)
    // SC : O(N)
    int approach_2(vector<int>& nums) {
        int n = nums.size();
        return func(nums, n, 0, 0);
    }

    // TC : O(2^N)
    // SC : O(1)
    int approach_3(vector<int>& nums) {
        int n = nums.size();
        int power = pow(2, n);
        int sum = 0;
        for (int counter = 0; counter < power; counter ++) {
            int sum_xor = 0;
            for (int i = 0; i < n; i ++) {
                if (counter & (1 << i)) {
                    sum_xor ^= nums[i];
                }
            }
            sum += sum_xor;
        }
        return sum;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_4(vector<int>& nums) {
        int n = nums.size();
        
        int all_ele_or = 0;
        for (int& num : nums) {
            all_ele_or |= num;
        }

        return all_ele_or << (n - 1);   // appending n-1 zeros
    }
public:
    int subsetXORSum(vector<int>& nums) {
        // return approach_1(nums);

        // return approach_2(nums);

        // return approach_3(nums);

        return approach_4(nums);        // Find OR of all ele & append (n-1) 0's in RHS
    }
};
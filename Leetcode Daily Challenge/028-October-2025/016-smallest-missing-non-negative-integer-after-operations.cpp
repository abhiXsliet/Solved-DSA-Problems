// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mpp;

        for (int &num : nums) {
            int r = ((num % value) + value) % value;
            mpp[r] ++;
        }

        int mex = 0;
        while (mpp[(mex % value)] > 0) {
            mpp[(mex % value)] --;

            mex += 1;
        }
        return mex;
    }
};
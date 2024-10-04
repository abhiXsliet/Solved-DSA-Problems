// https://leetcode.com/problems/make-sum-divisible-by-p/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        int target = 0;
        for (int& num : nums) {
            target = (target + num) % p;    // (a + b) % p = (a % p + b % p)
        }

        if (target == 0) return 0;

        unordered_map<int, int> mpp;    // to store the prev sum with index
        mpp[0]     = -1;    // sum 0 is seen at -1 index
        int curr   = 0;
        int minLen = n; // initialize with maxLen of subarray

        for (int j = 0; j < n; j ++) {
            curr = (curr + nums[j]) % p;

            int prev = (curr - target + p) % p; // to avoid negative value of prev

            if (mpp.count(prev)) {
                int i = mpp[prev];
                minLen = min(minLen, j - i);
            }

            mpp[curr] = j;
        }

        return minLen == n ? -1 : minLen;
    }
};
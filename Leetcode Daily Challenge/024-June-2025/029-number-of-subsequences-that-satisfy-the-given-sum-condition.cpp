// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int M = 1e9 + 7;
public:
    // TC : O(N * log(N))
    // SC : O(N)
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<long> powers(n + 1, 1);
        for (int i = 1; i <= n; i ++) {
            powers[i] = (powers[i - 1] * 2) % M;
        }

        int i = 0, j = n - 1, ans = 0;
        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                ans = (ans + powers[j - i]) % M;
                i ++;
            } else j --;
        }
        return ans;
    }
};
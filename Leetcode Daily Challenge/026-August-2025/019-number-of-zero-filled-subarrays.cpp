// https://leetcode.com/problems/number-of-zero-filled-subarrays/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        long long ans = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == 0) {
                if (prev == -1) {
                    prev = i;
                    ans += 1;
                } else {
                    ans += (i - prev + 1);
                }
            } else {
                prev = -1;
            }
        }
        return ans;
    }
};
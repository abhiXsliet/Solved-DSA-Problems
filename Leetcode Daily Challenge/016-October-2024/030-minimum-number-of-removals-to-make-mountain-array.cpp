// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N * N)
    // SC : O(N)
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);

        // Calculate the LIS till index i
        for (int i = 0; i < n; i ++) {
            for (int j = i - 1; j >= 0; j --) {
                if (nums[i] > nums[j]) {
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
        }

        // Caculate the LDS till index i
        for (int i = n - 1; i >= 0; i --) {
            for (int j = i + 1; j < n; j ++) {
                if (nums[i] > nums[j]) {
                    LDS[i] = max(LDS[i], 1 + LDS[j]);
                }
            }
        }

        int minRemoval = n;
        for (int i = 0; i < n; i ++) {
            if (LIS[i] > 1 && LDS[i] > 1)   // to maintain min mountain length of >= 3
                minRemoval = min(minRemoval, n - LIS[i] - LDS[i] + 1);
        }
        return minRemoval;
    }
};
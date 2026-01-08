// https://leetcode.com/problems/max-dot-product-of-two-subsequences/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    int mem(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp) {
        if (i == m || j == n) 
            return -1e8;
      
        if (dp[i][j] != -1e8) return dp[i][j];

        int val      = (nums1[i] * nums2[j]); // subseq. of size = 1
        int take_i_j = (nums1[i] * nums2[j]) + mem(nums1, nums2, i + 1, j + 1, dp);
        int take_i   = mem(nums1, nums2, i, j + 1, dp);
        int take_j   = mem(nums1, nums2, i + 1, j, dp);

        return dp[i][j] = max({val, take_i_j, take_i, take_j});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size(), n = nums2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1e8));
        return mem(nums1, nums2, 0, 0, dp);
    }
};
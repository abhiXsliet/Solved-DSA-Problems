// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

// similar problem : https://www.geeksforgeeks.org/problems/longest-common-substring1452/1


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;
    unordered_map<string, int> mpp;

    int solve(vector<int> &nums1, vector<int> &nums2, int i, int j, int maxL) {
        if (i == m || j == n)
            return maxL;

        string key = to_string(i) + "," + to_string(j) + "," + to_string(maxL);
        if (mpp.count(key))
            return mpp[key];

        int same = maxL;
        if (nums1[i] == nums2[j]) {
            same = solve(nums1, nums2, i + 1, j + 1, maxL + 1);
        }

        int op1 = solve(nums1, nums2, i + 1, j, 0);
        int op2 = solve(nums1, nums2, i, j + 1, 0);

        return mpp[key] = max({same, op1, op2});
    }

    // TC : O(M * N * min(M, N))
    // SC : O(M * N * min(M, N))
    int way_1(vector<int>& nums1, vector<int> &nums2) {
        mpp.clear();
        return solve(nums1, nums2, 0, 0, 0);
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int way_2(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        int maxL = 0;
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 0;
                }
                maxL = max(maxL, dp[i][j]);
            }
        }
        return maxL;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size(), n = nums2.size();

        // return way_1(nums1, nums2);
        return way_2(nums1, nums2);
    }
};
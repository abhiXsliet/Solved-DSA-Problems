// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int nextBestIndex(vector<int> &nums, int m, int tar) {
        int low = 0, high = m - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= tar) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    // TC : O(M*log(N))
    // SC : O(1)
    int approach_1(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int result = 0;
        for (int i = 0; i < m; i ++) {
            int nextIdx = nextBestIndex(nums2, n, nums1[i]);
            if (nextIdx >= i) result = max(result, nextIdx - i);
        }
        return result;
    }

    // TC : O(M + N)
    // SC : O(1)
    int approach_2(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;
        int result = 0;
        while (i < m  && j < n) {
            if (nums1[i] <= nums2[j]) {
                result = max(result, j - i);
                j ++;
            } else i ++;
        }
        return result;
    }
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        return approach_1(nums1, nums2);
        // return approach_2(nums1, nums2);
    }
};
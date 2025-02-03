// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int getMaxIncOrDecLength(vector<int>& nums, bool flag) {
        int n = nums.size();
        int maxLen = 1;
        int len = 1;
        for (int i = 0; i < n - 1; i ++) {
            if (!flag) {
                if (nums[i + 1] > nums[i]) len ++;
                else len = 1;
            } else {
                if (nums[i + 1] < nums[i]) len ++;
                else len = 1;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }

    // TC : O(N)
    // SC : O(1)
    int getIncreasing(vector<int>& nums, int i, int j) {
        int n = nums.size();
        int maxInc = 1;
        int len = 1;
        for (int x = i; x < j; x ++) {
            if (nums[x + 1] > nums[x]) {
                len ++;
                maxInc = max(maxInc, len);
            } else {
                len = 1;
            }
        }
        return maxInc;
    }
    
    // TC : O(N)
    // SC : O(1)
    int getDecreasing(vector<int>& nums, int i, int j) {
        int n = nums.size();
        int maxDec = 1;
        int len = 1;
        for (int x = i; x < j; x ++) {
            if (nums[x + 1] < nums[x]) {
                len ++;
                maxDec = max(maxDec, len);
            } else {
                len = 1;
            }
        }
        return maxDec;
    }
    
    // TC : O(N^3)
    // SC : O(1)
    int approach_1(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j ++) {
                int increasing = getIncreasing(nums, i, j);
                int decreasing = getDecreasing(nums, i, j);
                maxLen = max(maxLen, max(increasing, decreasing));
            }
        }
        return maxLen;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        int increasing = getMaxIncOrDecLength(nums, 0);
        int decreasing = getMaxIncOrDecLength(nums, 1);
        maxLen = max(maxLen, max(increasing, decreasing));
        return maxLen;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_3(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, maxInc = 1, dec = 1, maxDec = 1;
        for (int i = 0; i < n - 1; i ++) {
            if (nums[i + 1] > nums[i]) {
                inc ++;
                maxInc = max(maxInc, inc);
            } else {
                inc = 1;
            }

            if (nums[i + 1] < nums[i]) {
                dec ++;
                maxDec = max(maxDec, dec);
            } else {
                dec = 1;
            }
        }
        return max(maxInc, maxDec);
    }
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // return approach_1(nums); // BRUTE
        // return approach_2(nums); // Optimal : Double Traversal of Array
        return approach_3(nums); // Optimal : Single Traversal of Array
    }
};
// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(int k, vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        int len = 1;
        if (len == k) return true;
        for (int i = 0; i + k + 1 < n; i ++) {
            if (nums[i + 1] > nums[i] && nums[i + k + 1] > nums[i + k]) 
                len ++;
            else 
                len = 1;
            maxLen = max(maxLen, len);
        }
        return maxLen >= k;
    }
public:
    // TC : O(N * log(N))
    // SC : O(1)
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n/2, res = 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid, nums)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};
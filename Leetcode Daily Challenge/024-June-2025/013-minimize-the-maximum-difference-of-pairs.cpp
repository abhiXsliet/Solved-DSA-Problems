// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(vector<int> &nums, int n, int tar, int p) {
        int cntPairs = 0, i = 0;
        while (i + 1 < n) {
            int diff = nums[i + 1] - nums[i];
            if (diff <= tar) {
                cntPairs += 1;
                i += 2;
            } else {
                i += 1;
            }
        }
        return cntPairs >= p;
    }
public:
    // TC : O(N*log(R)) Where R = maxDiff b/w min. and max. element
    // SC : O(1)
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int low = 0, high = (nums[n - 1] - nums[0]);
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(nums, n, mid, p)) {
                ans  = mid;
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return ans;
    }
};
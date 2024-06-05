// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    int brute(vector<int>& nums, int n) {
        for (int x = 0; x <= n; x ++) {
            int cntOfNum = 0;
            for (int i = 0; i < n; i ++) {
                if (nums[i] >= x) cntOfNum ++;
            }
            if (cntOfNum == x) 
                return x;
        }
        return -1;
    }

    // TC : O(logN)
    // SC : O(1)
    int binarySearch(vector<int>& nums, int n, int x) { // LOWER BOUND
        int lo = 0, hi = n - 1, idx = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= x) {
                idx = mid;
                hi  = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return idx;
    }

    // TC : O(NlogN)
    // SC : O(1)
    int better(vector<int>& nums, int n) {
        sort(begin(nums), end(nums));
        for (int x = 0; x <= n; x ++) {
            // int idx = binarySearch(nums, n, x); // lower bound
            int idx = lower_bound(begin(nums), end(nums), x) - begin(nums);
            int cnt = n - idx;
            if (cnt == x) return x;
        }
        return -1;
    }

    // TC : O(NlogN + logN*logN)
    // SC : O(1)
    int better_2(vector<int>& nums, int n) {
        sort(begin(nums), end(nums));
        int x_low = 0, x_high = n;
        while(x_low <= x_high) {
            int x_mid = x_low + (x_high - x_low) / 2;

            int idx   = binarySearch(nums, n, x_mid);
            int cnt   = n - idx;

            if (cnt == x_mid) return x_mid;
            else if (cnt > x_mid) {
                x_low = x_mid + 1;
            } else {
                x_high = x_mid - 1;
            }
        }
        return -1;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int>& nums, int n) {
        vector<int> freq(n + 1, 0);
        for (int& num : nums) {
            freq[min(n, num)] ++;
        }

        int cumm_sum = 0;
        
        for (int x = freq.size() - 1; x >= 0; x --) {
            cumm_sum += freq[x];
            
            if (cumm_sum == x) {
                return cumm_sum;
            }
        }
        
        return -1;
    }
public:
    int specialArray(vector<int>& nums) {
        // return brute(nums, nums.size());

        // return better(nums, nums.size());

        // return better_2(nums, nums.size());

        return approach_2(nums, nums.size());
    }
};
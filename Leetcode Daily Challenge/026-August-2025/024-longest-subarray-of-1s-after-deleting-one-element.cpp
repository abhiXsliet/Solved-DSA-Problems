// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getMax(vector<int> &arr) {
        int n = arr.size(), k = 3;

        if (n == 1) return (!arr[0]) ? 0 : (arr[0] - 1);

        int i = 0, j = 0, sum = 0, maxi = INT_MIN;
        while (j < n) {
            sum += arr[j];
            if (j - i + 1 > 3) {
                sum -= arr[i];
                i ++;
            }
            maxi = max(maxi, sum);
            j ++;
        }
        return maxi;
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int> &nums) {
        vector<int> compressed;
        int consec = 0, prev = -1;
        for (int &val : nums) {
            if (!val) {
                if (consec) compressed.push_back(consec);
                consec = 0;
                prev = -1;
                compressed.push_back(val);
            } else {
                if (prev == -1) {
                    prev = val;
                    consec = 1;
                } else {
                    consec += 1;
                }
            }
        }
        if (consec) compressed.push_back(consec);

        return getMax(compressed);  // get maximum in a sliding window of size = 3
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int> &nums) {
        int n = nums.size();
        int i = 0, j = 0, sum = 0, maxi = INT_MIN, zeroCnt = 0;
        while (j < n) {
            if (!nums[j]) zeroCnt += 1;
            sum += nums[j];
            while (zeroCnt > 1) {
                if (!nums[i]) zeroCnt --;
                sum -= nums[i];
                i ++;
            }
            maxi = max(maxi, sum);
            j ++;
        }
        if (n == sum) maxi -= 1;
        return maxi;
    }
public:
    int longestSubarray(vector<int>& nums) {
        // return approach_1(nums);
        return approach_2(nums);     // O(1) space
    }
};
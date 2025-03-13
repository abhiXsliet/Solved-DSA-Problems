// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // this fn. returns the index of the first no. which is >= tar
    int binarySearch(vector<int>& nums, int tar) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= tar) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_1(vector<int> &nums) {
        int n = nums.size();
        auto positive = [&] (int num) {
            return num > 0;
        };
        auto negative = [&] (int num) {
            return num < 0;
        };
        int pos = count_if(begin(nums), end(nums), positive);
        int neg = count_if(begin(nums), end(nums), negative);
        return max(pos, neg);
    }

    // TC : O(log(N))
    // SC : O(1)
    int approach_2(vector<int> &nums) {
        int n = nums.size();
        int firstIdxOne = binarySearch(nums, 1);   // index of first no. >= 1
        int cntPos = n - firstIdxOne;

        int firstIdxZero = binarySearch(nums, 0);  // index of first no. >= 0
        int cntZeros = firstIdxOne - firstIdxZero;

        int cntNeg = firstIdxZero;

        return max(cntNeg, cntPos);
    }
public:
    int maximumCount(vector<int>& nums) {
        // return approach_1(nums);    // simple counting or stl count_if
        return approach_2(nums);    // binary-search : cnt(first no. >= 1) + cnt(first no. >= 0)
    }
};
// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int minDiff = INT_MAX;

        int i = 0;
        int j = i + k - 1;

        while(j < n) {
            int minElement = nums[i];
            int maxElement = nums[j];

            minDiff = min(minDiff, maxElement - minElement);
            i ++;
            j ++;
        }

        return minDiff;
    }
};
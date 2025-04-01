// https://leetcode.com/problems/sum-of-good-numbers/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        int sumGood = 0;
        for (int i = 0; i < n; i ++) {
            if (i - k >= 0 && i + k < n) {
                if (nums[i] > nums[i - k] && nums[i] > nums[i + k]) {
                    sumGood += nums[i];
                }
            } else if (i - k >= 0) { 
                if (nums[i] > nums[i - k]) {
                    sumGood += nums[i];
                }
            } else if (i + k < n) {
                if (nums[i] > nums[i + k]) {
                    sumGood += nums[i];
                }
            }
        }
        return sumGood;
    }
};
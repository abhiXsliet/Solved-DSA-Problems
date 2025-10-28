// https://leetcode.com/problems/make-array-elements-equal-to-zero/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int brute(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == 0) {
                int sumL = 0, sumR = 0;
                for (int j = i - 1; j >= 0; j --) {
                    sumL += nums[j];
                }
                for (int j = i + 1; j < n; j ++) {
                    sumR += nums[j];
                }
                if (abs(sumL - sumR) == 0) {
                    ans += 2;
                } else if (abs(sumL - sumR) == 1) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
    
    int optimal(vector<int>& nums) {
        int n = nums.size();
        vector<int> pSum(n, nums[0]);
        for (int i = 1; i < n; i ++) {
            pSum[i] = (pSum[i - 1] + nums[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == 0) {
                int sumL = pSum[i];
                int sumR = pSum[n - 1] - pSum[i];
                if (abs(sumL - sumR) == 0) {
                    ans += 2;
                } else if (abs(sumL - sumR) == 1) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
public:
    int countValidSelections(vector<int>& nums) {
        // return brute(nums);

        return optimal(nums);   // prefix sum
    }
};
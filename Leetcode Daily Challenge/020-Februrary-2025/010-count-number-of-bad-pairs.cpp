// https://leetcode.com/problems/count-number-of-bad-pairs/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // TC : O(N)
        // SC : O(N)
        long long countBadPairs(vector<int>& nums) {
            int n = nums.size();
            unordered_map<int, int> mpp;
            int sumOfCnt = 0;
            long long ans = 0;
            for (int i = 0; i < n; i ++) {
                int diff = nums[i] - i;
                if (mpp.count(diff)) {
                    sumOfCnt -= mpp[diff];
                } 
                ans += sumOfCnt;
                mpp[diff] ++;
                sumOfCnt += mpp[diff];
            }
            return ans;
        }
    };
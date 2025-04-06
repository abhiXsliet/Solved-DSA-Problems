// https://leetcode.com/problems/largest-divisible-subset/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;

    // TC : O(N^2)
    // SC : O(N)
    vector<int> approach_1(vector<int> &nums) {
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for (int i = 0; i < n; i ++) 
            hash[i] = i;

        int maxLis = 0, lastIdx = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i]   = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if (dp[i] > maxLis) {
                maxLis  = dp[i];
                lastIdx = i;
            }
        }

        vector<int> result;
        while (lastIdx != hash[lastIdx]) {
            result.push_back(nums[lastIdx]);
            lastIdx = hash[lastIdx];
        }
        result.push_back(nums[lastIdx]);
        
        reverse(begin(result), end(result));
        return result;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n = nums.size();

        sort(begin(nums), end(nums));
        return approach_1(nums);
    }
};
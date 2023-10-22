// https://leetcode.com/contest/weekly-contest-368/problems/minimum-sum-of-mountain-triplets-i/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    if (i < j < k && nums[i] < nums[j] && nums[k] < nums[j]) {
                        int sum = nums[i] + nums[j] + nums[k];
                        ans = min(sum, ans);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
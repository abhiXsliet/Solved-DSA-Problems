// https://leetcode.com/contest/weekly-contest-368/problems/minimum-sum-of-mountain-triplets-ii/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> rightMin(n, INT_MAX);
        vector<int>  leftMin(n, INT_MAX);

        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i-1], nums[i-1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i+1], nums[i+1]);
        }

        int ans = INT_MAX;

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > leftMin[i] && nums[i] > rightMin[i]) {
                ans = min(ans, nums[i] + leftMin[i] + rightMin[i]);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
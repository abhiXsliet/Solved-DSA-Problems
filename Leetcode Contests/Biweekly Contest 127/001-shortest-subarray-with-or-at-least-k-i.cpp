// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-i/description/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j ++) {
                int val = 0;
                for (int k = i; k <= j; k++) {
                    val |= nums[k];
                }
                if (val >= k) {
                    ans = min(ans, j - i + 1);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
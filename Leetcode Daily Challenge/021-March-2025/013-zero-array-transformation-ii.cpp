// https://leetcode.com/problems/zero-array-transformation-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(limit + N) limit could be at max Queries length
    // SC : O(N)
    bool isPossibleToMakeZero(vector<int> &nums, int n, vector<vector<int>> &queries, int limit) {
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < limit; i ++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int v = queries[i][2];
            diff[l]     -= v;
            diff[r + 1] += v;
        }

        for (int i = 1; i <= n; i ++) {
            diff[i] += diff[i - 1];
        }

        for (int i = 0; i < n; i ++) {
            if (nums[i] + diff[i] > 0) {
                return false;
            } 
        }
        return true;
    }

    // TC : O(Q * log(Q))
    // SC : O(N)
    int approach_1(vector<int> &nums, vector<vector<int>> &queries) {
        int n = nums.size(), q = queries.size();
        
        int low = 0, high = q; 
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossibleToMakeZero(nums, n, queries, mid)) {
                ans  = mid;
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return ans;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        return approach_1(nums, queries);
    }
};
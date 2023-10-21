// https://leetcode.com/problems/constrained-subsequence-sum/


#include <bits/stdc++.h>
using namespace std;    

class Solution {
    private:
    // TC = O(N * log(N))
    // SC = O(N)
    int solve_tab_optimized(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
        }
        // max heap
        priority_queue<pair<int, int>> pq; // {maxElement, index}
        pq.push({dp[0], 0});

        int result = dp[0];
        
        // O(N * log(N))
        for (int i = 1; i < n; i++) {
            
            while(!pq.empty() && i - pq.top().second > k) {
                pq.pop();
            }

            dp[i] = max(dp[i], nums[i] + pq.top().first);

            pq.push({dp[i], i});

            result = max(dp[i], result);
        }

        return result;
    }

    // TC = O(N * N)
    // SC = O(N)
    int solve_tabulation(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
        }

        int result = dp[0];

        for (int i = 0; i < n; i++) {

            for (int j = i - 1; j >= 0 && i - j <= k; j--) {
                
                dp[i] = max(dp[i], nums[i] + dp[j]);

                result = max(result, dp[i]);
            }
        }

        return result;
    }

    // TC = O(N * N)
    // SC = O(N)
    int solve_mem(vector<int>& nums, int k, int idx, int prev, unordered_map<string, int>& mpp) {
        
        if (idx >= nums.size())
            return 0;

        string key = to_string(prev) + "_" + to_string(idx);

        if (mpp.find(key) != mpp.end()) {
            return mpp[key];
        }

        int result = 0;
        if (prev == -1 || idx - prev <= k) {
            int incl = nums[idx] + solve_mem(nums, k, idx+1, idx, mpp);
            int excl = solve_mem(nums, k, idx+1, prev, mpp);

            result = max(incl, excl);
        }

        return mpp[key] = result;
    }

    // TC = O(2^N)
    // SC = O(N) -> due to recursive call stack
    int solve_rec(vector<int>& nums, int k, int idx, int prev) {
        int n = nums.size();

        if (idx >= n)
            return 0;

        int result = 0;
        if (prev == -1 || idx - prev <= k) {
            int incl = nums[idx] + solve_rec(nums, k, idx+1, idx);
            int excl = 0 + solve_rec(nums, k, idx+1, prev);

            result = max(incl, excl);
        }

        return result;
    }

    int solve_recursively(vector<int>& nums, int k) {
        int val = solve_rec(nums, k, 0, -1);
        if (val == 0) {
            return *max_element(begin(nums), end(nums));
        }
        else return val;
    }

    int solve_memoization(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<string, int> mpp;

        int val = solve_mem(nums, k, 0, -1, mpp);

        if (val == 0) {
            return *max_element(begin(nums), end(nums));
        }
        else return val;
    }
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // return solve_recursively(nums, k);

        // return solve_memoization(nums, k);

        // return solve_tabulation(nums, k);

        return solve_tab_optimized(nums, k);
    }
};
// https://leetcode.com/problems/largest-divisible-subset/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(k^2), where k is the size of the subset.
    bool isValidSubset(vector<int>& subset) {
        for (int i = 0; i < subset.size(); ++i) {
            for (int j = 0; j < subset.size(); ++j) {
                if (i != j && subset[i] % subset[j] != 0 && subset[j] % subset[i] != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    // TC: O(2^n * n^2), where n is the size of the input array nums.
    // SC: O(n), where n is the size of the input array nums.
    vector<int> solve_brute(vector<int>& nums, int n) {
        vector<int> t;
        for (long long p = 0; p < (1 << n); p++) {
            vector<int> subsets;
            for (int i = 0; i < n; i++) {
                if (p & (1 << i)) {
                    subsets.push_back(nums[i]);
                }
            }

            if (isValidSubset(subsets) && subsets.size() > t.size()) {
                t = subsets;
            }
        }
        return t;
    }

    // T.C : O(2^n) without memoization
    // S.C : O(n)
    void solve(vector<int>& nums, int n, int idx, int prev, vector<int>& temp, vector<int>& result) {
        if (idx == n) {
            if (temp.size() > result.size()) {
                result = temp;
            }
            return;
        }

        if (prev == -1 || nums[idx] % prev == 0) {
            temp.push_back(nums[idx]);
            solve(nums, n, idx + 1, nums[idx], temp, result);
            temp.pop_back();
        }

        solve(nums, n, idx + 1, prev, temp, result);
    }

    vector<int> solve_rec(vector<int>& nums, int n) {
        sort(begin(nums), end(nums));

        vector<int> result;
        vector<int> temp;

        int prev = -1;

        solve(nums, n, 0, prev, temp, result);

        return result;
    }

    // TC : O(N^2)
    // SC : O(N)
    vector<int> solve_tab(vector<int>& nums, int n) {
        sort(begin(nums), end(nums));

        vector<int> t(n, 1);         // at least one subset is possible 
        vector<int> prev_idx(n, -1); // keep track of prev_idx 

        int last_choosen_idx = 0;
        int maxLen           = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {

                if (nums[i] % nums[j] == 0) {

                    if (t[i] < t[j] + 1) {
                        
                        t[i] = t[j] + 1;
                        
                        prev_idx[i] = j;
                    }

                    if (t[i] > maxLen) {

                        maxLen = t[i];

                        last_choosen_idx = i;
                    }
                }
            }
        }

        vector<int> result;

        while (last_choosen_idx >= 0) {
            result.push_back(nums[last_choosen_idx]);

            last_choosen_idx = prev_idx[last_choosen_idx];
        }

        return result;
    }

    // TC : O(N^2)
    // SC : O(N)
    vector<int> solve_tab_2(int n, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n, 1), parent(n, -1);
        int max_size = 0, max_val_idx = 0;

        // Compute the length of the longest divisible subset
        for (int curr = 0; curr < n; curr ++) {
            for (int prev = 0; prev < curr; prev ++) {

                if (nums[curr] % nums[prev] == 0 && dp[prev] + 1 > dp[curr]) {
                    dp[curr]     = dp[prev] + 1;
                    parent[curr] = prev;
                }
            }
            if (dp[curr] > max_size) {
                max_size    = dp[curr];
                max_val_idx = curr;
            }
        }

        // Reconstruct the largest divisible subset
        vector<int> answer;
        while (max_val_idx >= 0) {
            answer.push_back(nums[max_val_idx]);
            max_val_idx = parent[max_val_idx];
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // return solve_brute(nums, nums.size());

        // return solve_rec(nums, nums.size());

        // return solve_tab(nums, nums.size());

        return solve_tab_2(nums.size(), nums);
    }
};
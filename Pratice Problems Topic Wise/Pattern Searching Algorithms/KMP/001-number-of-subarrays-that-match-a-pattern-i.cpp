// https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*M)
    // SC : O(1)
    int solve_brute_1(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();

        int ans = 0;
        for (int i = 0; i < n - m; i++) {
            int idx = 0;
            int j   = i + 1;
            while(idx < m) {
                if (pattern[idx] == 1 && nums[j]  > nums[j - 1] ||
                    pattern[idx] == 0 && nums[j] == nums[j - 1] || 
                    pattern[idx] == -1 && nums[j] < nums[j - 1] ) {
                    if (j - i + 1 == m + 1) {
                        ans += 1;
                    }
                    j ++, idx ++;
                }
                else break;
            }
        }
        return ans;
    }
    
    // TC : O(N*M)
    // SC : O(1)
    int solve_brute_2(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();

        int ans = 0;
        for (int i = 0; i < n - m; i++) {
            int k = 0;
            while(k < m) {
                if (pattern[k] == 1 && nums[i + k + 1]  > nums[i + k] ||
                    pattern[k] == 0 && nums[i + k + 1] == nums[i + k] || 
                    pattern[k] ==-1 && nums[i + k + 1]  < nums[i + k] ) {
                    k ++;
                }
                else break;
                if (k == m) {
                    ans += 1;
                }
            }
        }
        return ans;
    }

    // TC : O(M) Where M = Pattern Length
    // SC : O(M)
    vector<int> get_prefix(vector<int>& nums) {
        int m = nums.size();
        vector<int> prefix_idx(m, 0);
        for (int i = 1; i < m; i++) {
            int j = prefix_idx[i - 1];
            
            while (j > 0 && nums[i] != nums[j]) {
                j = prefix_idx[j - 1];
            }

            if (nums[i] == nums[j]) j ++;
            prefix_idx[i] = j;
        }
        return prefix_idx;
    }

    // TC : O(N + M)
    // SC : O(N)
    int solve_optimal(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();

        vector<int> temp;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                temp.push_back(1);
            }
            else if (nums[i] < nums[i - 1]) {
                temp.push_back(-1);
            }
            else if (nums[i] == nums[i - 1]) {
                temp.push_back(0);
            }
        }

        vector<int> pref = get_prefix(pattern);
        
        int i = 0, j = 0, ans = 0;
        while (i < temp.size()) {
            if (temp[i] == pattern[j]) 
                i ++, j ++;
            else {
                if (j != 0) 
                    j = pref[j - 1];
                else i ++;
            }

            if (j == m) {
                ans += 1;
                j = pref[j - 1];
            }
        }
        return ans;
    }
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        // return solve_brute_1(nums, pattern);
        // return solve_brute_2(nums, pattern);

        return solve_optimal(nums, pattern);
    }
};
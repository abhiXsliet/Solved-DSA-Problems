// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^3)
    // SC : O(1)
    int solve_brute(vector<int>& nums, int n, int k) {
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                unordered_map<int, int> mpp;
                for (int k = i; k <= j; k ++) {
                    mpp[nums[k]] ++;
                }

                for (auto& it : mpp) {
                    if (it.second > k) {
                        mpp.clear();
                        break;
                    }
                }
                
                int len = 0;
                for (auto& it : mpp) {
                    len += it.second;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
    
    // TC : O(N)
    // SC : O(N)
    int solve_optimal_1(vector<int>& nums, int n, int k) {
        unordered_map<int, int> mpp;
        
        int i = 0, j = 0;
        int maxLen = 0;
        while (j < n && i < n) {
            mpp[nums[j]] ++;
        
            while (mpp[nums[j]] > k) {
                mpp[nums[i]]--;
                i++;
            }
            
            j++;
            maxLen = max(maxLen, j - i);
        }
        return maxLen;
    }

    // TC : O(N)
    // SC : O(N)
    int solve_optimal_2(vector<int>& nums, int n, int k) {
        unordered_map<int, int> mpp;
        
        int i = 0, j = 0;
        int maxLen  = 0;
        int culprit = 0;

        while (j < n) {
            mpp[nums[j]] ++;
            
            if (mpp[nums[j]] == k + 1) {
                culprit ++;
            }
            if (culprit) {
                mpp[nums[i]] --;
                if (mpp[nums[i]] == k) {
                    culprit --;
                }
                i ++;
            }
            j++;
            maxLen = max(maxLen, j - i);
        }
        return maxLen;
    }
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // return solve_brute(nums, nums.size(), k);

        // return solve_optimal_1(nums, nums.size(), k);

        return solve_optimal_2(nums, nums.size(), k);       // Without Nested Loops
    }
};
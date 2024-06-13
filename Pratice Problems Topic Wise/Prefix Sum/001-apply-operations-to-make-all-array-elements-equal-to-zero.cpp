// https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    bool brute(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = n - 1; i >= 0; i --) {
            if (i - k + 1 >= 0) {  // Ensure valid range for subarray
                int mini = INT_MAX;
                for (int m = i; m >= i - k + 1; m--) {  // Loop through valid subarray
                    mini = min(mini, nums[m]);
                }
                
                int temp = k;
                for (int j = i; j >= i - k + 1; j --) {
                    nums[j] -= mini;
                }
            }
        }

        for (int i = 0; i < n; i ++) {
            if (nums[i] != 0) 
                return 0;
        }
        return 1;
    }

    // TC : O(N^2)
    // SC : O(1)
    bool brute_2(vector<int>& nums, int k) {
        int n = nums.size();
        
        for (int i = 0; i <= n - k; i++) {
            int mini = nums[i];
            for (int j = i; j < i + k; j++) {
                mini = min(mini, nums[j]);
            }

            for (int j = i; j < i + k; j++) {
                nums[j] -= mini;
            }
        }

        for (auto& num : nums) {
            if (num != 0) return false;
        }
        
        return true;
    }

    // TC : O(N)
    // SC : O(N)
    bool optimal_way_1(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);   // Subtracting prefix[i] from nums[i] to make it zero
        
        prefix[0]     += nums[0];
        prefix[0 + k] -= nums[0];
        
        for (int i = 1; i < n; i ++) {
            prefix[i] += prefix[i - 1];
            if (prefix[i] == nums[i]) continue;
            if (prefix[i] > nums[i] || i + k > n) 
                return false;
            
            long extra = (long)nums[i] - prefix[i];
            prefix[i] += extra;
            prefix[i + k] -= extra;
        }
        return 1;
    }

    // TC : O(N)
    // SC : O(N)
    bool optimal_way_2(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);   // Subtracting prefix[i] from nums[i] to make it zero
        
        prefix[0]     -= nums[0];
        prefix[0 + k] += nums[0];
        
        for (int i = 1; i < n; i ++) {
            prefix[i] += prefix[i - 1];
            
            if (nums[i] + prefix[i] == 0) continue;
            if (prefix[i] > nums[i] || i + k > n) 
                return false;
            
            long extra = (long)nums[i] + prefix[i];
            prefix[i] -= extra;
            prefix[i + k] += extra;
        }
        return 1;
    }
public:
    bool checkArray(vector<int>& nums, int k) {
        // return brute(nums, k);          // L <------- R (Solution)

        // return brute_2(nums, k);        // L -------> R (Solution)

        // PENDING : SEGMENT TREE APPROACH ??

        // return optimal_way_1(nums, k);  // Prefix Difference Approach : +ve values in prefix array

        return optimal_way_2(nums, k);  // Prefix Difference Approach : -ve values in prefix array
    }
};
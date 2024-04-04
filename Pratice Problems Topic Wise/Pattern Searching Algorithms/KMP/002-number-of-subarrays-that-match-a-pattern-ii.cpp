// https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
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
public:
    // TC : O(N + M)
    // SC : O(N)
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
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
};
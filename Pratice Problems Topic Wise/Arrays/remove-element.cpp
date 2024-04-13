// https://leetcode.com/problems/remove-element/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N) 
    int solve_1(vector<int>& nums, int val) {
        int n   = nums.size();
        vector<int> ans;
        for (int& num : nums) {
            if (num != val) {
                ans.push_back(num);
            }
        }
        int m = ans.size();
        for (int i = 0; i < n; i++) {
            if (i < m) nums[i] = ans[i];
        }
        return m;
    }

    // TC : O(N)
    // SC : O(1) 
    int solve_2(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0, j = n - 1;
        int cntVal = 0;
        while (i <= j) {
            if (nums[i] == val && nums[j] != val) {
                cntVal += 1;
                swap(nums[i], nums[j]);
                i ++, j --;
            }
            else if (nums[j] == val) {
                cntVal += 1;
                j --;
            }
            else i ++;
        }
        return n - cntVal;
    }
public:
    int removeElement(vector<int>& nums, int val) {
        // return solve_1(nums, val);

        return solve_2(nums, val);
    }
};
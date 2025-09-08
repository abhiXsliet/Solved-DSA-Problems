// https://leetcode.com/contest/weekly-contest-466/problems/count-bowl-subarrays/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> stk;
    
        for (int i = 0; i < n; i ++) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
    
        while (!stk.empty()) stk.pop();
    
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
    
        long res = 0;
        for (int i = 0; i < n; i ++) {
            if (left[i] != -1 && i - left[i] >= 2) {
                res ++;
            }
            if (right[i] != n && right[i] - i >= 2) {
                res ++;
            }
        }
    
        return res;
    }
};
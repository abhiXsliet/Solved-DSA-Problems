// https://leetcode.com/problems/jump-game/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int t[10001];
    bool solve(vector<int>& nums, int i, int n) {
        if (i >= n - 1) return 1;
        if (t[i] != -1) return t[i];
        for (int jump = 1; jump <= nums[i]; jump ++) {
            if(solve(nums, i + jump, n))
                return t[i] = true;
        }
        return t[i] = false;
    }
    
    // TC : O(N)
    // SC : O(1)
    bool greedy(vector<int>& nums, int n) {
        int maxR = nums[0];
        for (int i = 0; i < n;) {
            int maxJump = i + nums[i];
            if (maxJump >= n - 1) return true;
            if (maxJump == i) return false;
            for (int j = i + 1; j <= maxJump; j ++) {
                maxR -= 1;
                i = j;
                if (maxR < nums[j]) {
                    maxR = nums[j];
                    break;
                }
            }
        }
        return false;
    }

    bool greedy_optimized(vector<int>& nums, int n) {
        int maxR = 0;
        for (int i = 0; i < n; i ++) {
            if (i > maxR) return false;
            maxR = max(maxR, i + nums[i]);
            if (maxR >= n - 1) return true;
        }
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        // memset(t, -1, sizeof(t));
        // return solve(nums, 0, nums.size());

        // return greedy(nums, nums.size());
        return greedy_optimized(nums, nums.size());
    }
};
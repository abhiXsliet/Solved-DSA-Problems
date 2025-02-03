// https://leetcode.com/problems/jump-game-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int t[10001];
    // TC : O(N^2)
    // SC : O(N)
    int solve(vector<int>& nums, int i, int n) {
        if (i >= n - 1) return 0;
        if (t[i] != -1) return t[i];
        int maxRes = n;
        for (int jump = 1; jump <= nums[i]; jump ++) {
            maxRes = min(maxRes,  1 + solve(nums, i + jump, n));
        }
        return t[i] = maxRes;
    }

    // TC : O(N)
    // SC : O(1)
    int greedy(vector<int>& nums, int n) {
        if (n == 1) return 0;
        int jumps = 0;
        int maxR = nums[0];
        for (int i = 0; i < n;) {
            int maxJump = i + nums[i];
            if (maxJump >= n - 1) return jumps + 1;
            for (int j = i + 1; j <= maxJump; j ++) {
                maxR -= 1;
                if (maxR < nums[j]) {
                    maxR = nums[j];
                    i = j;
                }
            }
            jumps ++;
        }
        return jumps;
    }

    int greedy_optimized(vector<int>& nums, int n) {
        int maxR = nums[0], maxE = nums[0];
        int jumps = 1;
        for (int i = 0; i < n; i ++) {
            maxR = max(maxR, i + nums[i]);
            if (maxE == i) {
                jumps ++;
                maxE = maxR;
            }
        }
        return jumps;
    }
public:
    int jump(vector<int>& nums) {
        // memset(t, -1, sizeof(t));
        // return solve(nums, 0, nums.size());

        // return greedy(nums, nums.size());    
        return greedy_optimized(nums, nums.size());
    }
};
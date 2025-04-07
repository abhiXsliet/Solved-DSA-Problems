// https://leetcode.com/problems/maximum-alternating-subsequence-sum/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    typedef long long ll;
    ll t[100001][2];

    ll solve(vector<int>& nums, int i, bool positive) {
        if (i >= n) return 0;

        if (t[i][positive] != -1)
            return t[i][positive];

        ll op1 = (positive ? nums[i] : -nums[i]) + solve(nums, i + 1, !positive);
        ll op2 = solve(nums, i + 1, positive); 

        return t[i][positive] = max(op1, op2);
    }

    // TC : O(N)
    // SC : O(N)
    ll top_down(vector<int> &nums) {
        memset(t, -1, sizeof(t));
        return solve(nums, 0, 1);
    }

    // TC : O(N)
    // SC : O(N)
    ll bottom_up(vector<int> &nums) {
        memset(t, 0, sizeof(t));
        for (int i = n - 1; i >= 0; i --) {
            for (int positive = 0; positive <= 1; positive ++) {
                ll op1 = (positive ? nums[i] : -nums[i]) + t[i + 1][!positive];
                ll op2 = t[i + 1][positive]; 

                t[i][positive] = max(op1, op2);
            }
        }
        return t[0][1];
    }

    // TC : O(N)
    // SC : O(1)
    ll space_optimized(vector<int> &nums) {
        vector<ll> prev(2, 0), curr(2, 0);
        for (int i = n - 1; i >= 0; i --) {
            for (int positive = 0; positive <= 1; positive ++) {
                ll op1 = (positive ? nums[i] : -nums[i]) + prev[!positive];
                ll op2 = prev[positive]; 

                curr[positive] = max(op1, op2);
            }
            prev = curr;
        }
        return prev[1];
    }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();

        // return top_down(nums);
        // return bottom_up(nums);
        return space_optimized(nums);
    }
};
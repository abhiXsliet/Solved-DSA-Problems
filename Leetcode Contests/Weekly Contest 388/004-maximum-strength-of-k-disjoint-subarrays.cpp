// https://leetcode.com/problems/maximum-strength-of-k-disjoint-subarrays/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    vector<vector<vector<ll>>> dp;

    // TC : O(n*k*2) ~= O(n*k)
    // SC : O(n*k*2) ~= O(n*k)
    ll mem(int i, ll k, vector<int>& nums, bool create_new_subarray) {
        if (k == 0) return 0;

        // -10^9 to 10^9 sum : 0
        // -10^9 to 0 => sum : -1e^19
        if (i >= nums.size()) 
            return -1e18;   // returning least min value since sum could be -ve sometimes
        
        if (dp[i][k][create_new_subarray] != -1) 
            return dp[i][k][create_new_subarray];

        ll take     = -1e18;
        ll not_take = -1e18;

        // We can't continue past subarray with skipping current element
        // so when we skip we MUST start a new subarray
        if (create_new_subarray) {
            not_take = mem(i + 1, k, nums, true);   // skip present element
        }

        if (k % 2 != 0) {   // odd : (-1)^1+odd = +
            // take and continue 
            take = mem(i + 1, k, nums, false) + nums[i] * k;
            // take and close and create a new subarray
            take = max(take, mem(i + 1, k - 1, nums, true) + nums[i] * k);
        }
        else {  // even : (-1)^1+even = -
            // take and continue
            take = mem(i + 1, k, nums, false) - nums[i] * k;
            // take and close and create a new subarray
            take = max(take, mem(i + 1, k - 1, nums, true) - nums[i] * k);
        }

        return dp[i][k][create_new_subarray] = max(take, not_take);
    }
public:
    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        dp.resize(n + 1, vector<vector<ll>>(k + 1, vector<ll>(2, -1)));
        bool create_new_subarray = 1;
        return mem(0, k, nums, create_new_subarray);
    }
};
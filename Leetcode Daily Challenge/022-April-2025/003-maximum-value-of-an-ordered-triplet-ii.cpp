// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    using ll = long long;

    // TC : O(N)
    // SC : O(N)
    ll approach_1(vector<int> &nums) {
        int n = nums.size();
        vector<int> prefix(n, nums[0]), suffix(n, nums[n - 1]);
        for (int i = 1; i < n; i ++) {
            prefix[i] = max(nums[i], prefix[i - 1]);
        }
        for (int i = n - 2; i >= 0; i --) {
            suffix[i] = max(suffix[i + 1], nums[i]);
        }
        ll ans = 0;
        for (int i = 1; i < n - 1; i ++) {
            ll val = (prefix[i] - nums[i]) * (ll)(suffix[i + 1]);
            ans = max(ans, val);
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(1)
    ll approach_2(vector<int> &nums) {
        int n = nums.size();
        int maxDiff = INT_MIN;
        int prefix = nums[0];
        ll result = 0;
        for (int i = 1; i < n - 1; i ++) {
            prefix  = max(prefix, nums[i]);
            maxDiff = max(maxDiff, prefix - nums[i]);
            result  = max(result, ((ll)maxDiff * nums[i + 1]));
        }
        return result;
    }
public:
    long long maximumTripletValue(vector<int>& nums) {
        // return approach_1(nums);
        return approach_2(nums);
    }
};
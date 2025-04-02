// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    int n;

    // TC : O(N^3)
    // SC : O(1)
    ll approach_1(vector<int> &nums) {
        ll ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                for (int k = j + 1; k < n; k ++) {
                    ll val = (nums[i] - nums[j]) * (ll)nums[k];
                    ans = max(ans, val);
                }
            }
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(N)
    ll approach_2(vector<int> &nums) {
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
public:
    long long maximumTripletValue(vector<int>& nums) {
        n = nums.size();

        // return approach_1(nums);
        return approach_2(nums);
    }
};
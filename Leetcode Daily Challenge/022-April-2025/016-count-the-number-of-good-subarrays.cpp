// https://leetcode.com/problems/count-the-number-of-good-subarrays/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    // TC : O(N)
    // SC : O(N)
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<ll, ll> mpp;
        ll ans = 0, pairs = 0;
        int i = 0, j = 0;
        while (j < n) {
            pairs += mpp[nums[j]];
            mpp[nums[j]] ++;
            while (pairs >= k) {
                ans += (n - j);
                mpp[nums[i]] --;
                pairs -= mpp[nums[i]];
                i ++;
            }
            j ++;
        }
        return ans;
    }
};
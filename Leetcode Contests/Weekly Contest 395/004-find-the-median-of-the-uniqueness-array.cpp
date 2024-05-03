// https://leetcode.com/problems/find-the-median-of-the-uniqueness-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    ll cntSubArrays(vector<int>& nums, int k, int n) {
        unordered_map<ll, ll> freq;
        ll i = 0, j = 0, subCnt = 0;
        while (j < n) {
            freq[nums[j]] ++;
            while (freq.size() > k) {
                freq[nums[i]] --;
                if (freq[nums[i]] == 0) {
                    freq.erase(nums[i]);
                }
                i ++;
            }
            subCnt += j - i + 1;
            j ++;
        }
        return subCnt;
    }
public:
    // TC : O(N*Log(N))
    // SC : O(N)        Where N = No. of Unique elements
    int medianOfUniquenessArray(vector<int>& nums) {
        ll n = nums.size();
        unordered_set<int> st(begin(nums), end(nums));

        ll totSubArrayCnt = (n * (n + 1)) / 2;
        ll medianSubArray = (totSubArrayCnt + 1) / 2;

        ll low = 1, high = st.size(), ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            // is possible to have subarrays cnt >= medianSubArray whose distinct ele <= mid ?
            if (cntSubArrays(nums, mid, n) >= medianSubArray) {
                ans  = mid;
                high = mid - 1;
            }
            else {
                low  = mid + 1;
            }
        }
        return (int)ans;
    }
};
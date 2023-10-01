// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxVal = 0;
        vector<int> prefix(n), suffix(n);
        prefix[0] = INT_MIN;

        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], nums[i - 1]);
        }

        suffix[n - 1] = INT_MIN;
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], nums[i + 1]);
        }

        for (int i = 1; i < n - 1; i++) {
            maxVal = max( maxVal, ( (prefix[i]-nums[i]) * (long long)(suffix[i]) ) );
        }
        return maxVal;
    }
};
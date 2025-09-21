// https://leetcode.com/contest/weekly-contest-468/problems/maximum-total-subarray-value-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long maxTotalValue(vector<int>& nums, int k) {
        ll res = 0;
        int maxi = INT_MIN, mini = INT_MAX;
        for (int &num : nums) {
            maxi = max(maxi, num);
            mini = min(mini, num);
        }
        int diff = maxi - mini;
        return (ll)diff * k;
    }
};
// https://leetcode.com/problems/find-the-integer-added-to-array-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums2), end(nums2));
        sort(begin(nums1), end(nums1));
        int len = nums1.size();
        int ans = INT_MIN;
        for (int i = 0; i < len; i++) {
            ans = max(ans, nums2[i] - nums1[i]);
        }
        return ans;
    }
};
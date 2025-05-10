// https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    // TC : O(N + M)
    // SC : O(1)
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll sum1 = 0;
        int zo1 = 0;
        for (int &num : nums1) {
            if (num == 0) {
                zo1 += 1;
            } else {
                sum1 += num;
            }
        } 

        ll sum2 = 0;
        int zo2 = 0;
        for (int &num : nums2) {
            if (num == 0) {
                zo2 += 1;
            } else {
                sum2 += num;
            }
        }   
        
        if (zo1 == 0 && zo2 == 0) {
            return (sum1 == sum2) ? sum1 : -1;
        } else if (zo2 == 0) {
            return (sum1 + zo1) <= sum2 ? sum2 : -1;
        } else if (zo1 == 0) {
            return (sum2 + zo2) <= sum1 ? sum1 : -1;
        } 
        return max((sum1 + zo1), (sum2 + zo2));
    }
};
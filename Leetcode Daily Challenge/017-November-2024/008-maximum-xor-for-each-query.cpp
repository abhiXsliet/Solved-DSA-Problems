// https://leetcode.com/problems/maximum-xor-for-each-query/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        int xor_all = 0;
        for (int &num : nums) {
            xor_all ^= num;
        }

        int mask = ((1 << maximumBit) - 1);

        vector<int> result(n, 0);
        for (int i = 0; i < n; i ++) {
            int k = mask ^ xor_all;
            result[i] = k;
            
            xor_all ^= nums[n - i - 1];
        }
        return result;
    }
};
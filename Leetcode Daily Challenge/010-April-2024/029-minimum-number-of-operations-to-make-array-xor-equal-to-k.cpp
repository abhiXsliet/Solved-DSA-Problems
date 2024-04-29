// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int minOperations(vector<int>& nums, int k) {
        int totalXor = 0;
        
        for(int &num : nums) {
            totalXor ^= num;
        }
        
        int diff = (totalXor ^ k);
        
        return __builtin_popcount(diff);
    }
};
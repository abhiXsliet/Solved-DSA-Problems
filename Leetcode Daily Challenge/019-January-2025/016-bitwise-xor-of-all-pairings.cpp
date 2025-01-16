// https://leetcode.com/problems/bitwise-xor-of-all-pairings/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:    
    // TC : O(N)
    // SC : O(1)
    int approach_1(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        int xor_num1 = 0;
        if (n % 2) {
            for (int &val : nums1) {
                xor_num1 ^= val;
            }
        } 

        int xor_num2 = 0;
        if (m % 2) {
            for (int &val : nums2) {
                xor_num2 ^= val;
            }
        }

        return xor_num1 ^ xor_num2;
    }
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        return approach_1(nums1, nums2);
    }
};
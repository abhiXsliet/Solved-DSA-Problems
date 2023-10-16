// https://leetcode.com/contest/weekly-contest-365/problems/maximum-value-of-an-ordered-triplet-i/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxVal = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    maxVal = max(maxVal, (long long)(nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        
        return maxVal;
    }
};
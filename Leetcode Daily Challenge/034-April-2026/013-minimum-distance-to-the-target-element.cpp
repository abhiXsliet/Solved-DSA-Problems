// https://leetcode.com/problems/minimum-distance-to-the-target-element/




#include <bits/stdc++.h>    
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int minD = INT_MAX;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == target) {
                minD = min(minD, abs(i - start));
            }
        }
        return minD;
    }
};
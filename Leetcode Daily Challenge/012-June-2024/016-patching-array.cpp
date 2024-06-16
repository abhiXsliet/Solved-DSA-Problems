// https://leetcode.com/problems/patching-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(L + log(N)) Where L = nums.size()
    int minPatches(vector<int>& nums, int n) {
        long maxReach = 0;
        int patchCnt  = 0;
        int i         = 0;

        while (maxReach < n) {
            if (i < nums.size() && nums[i] <= maxReach + 1) {
                maxReach += nums[i];
                i ++;
            } else {
                maxReach += (maxReach + 1);
                patchCnt += 1;
            }
        }
        return patchCnt;
    }
};
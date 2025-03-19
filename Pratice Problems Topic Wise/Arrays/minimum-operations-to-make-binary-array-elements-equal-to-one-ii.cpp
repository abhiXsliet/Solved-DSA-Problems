// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flipCnt = 0;
        for (int i = 0; i < n; i ++) {
            if ((flipCnt % 2) == nums[i]) { // flip it
                flipCnt += 1;
            }
        }
        return flipCnt;
    }
};
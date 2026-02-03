// https://leetcode.com/problems/trionic-array-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        bool isInc = 0;
        for (int i = 0; i < n - 1; i ++) {
            if (nums[i + 1] > nums[i]) {
                if (!isInc) {
                    cnt += 1;
                    isInc = 1;
                }
            } else if (nums[i + 1] < nums[i]) {
                if (isInc) {
                    cnt += 1;
                    isInc = 0;
                } else {
                    if (cnt == 0) return 0; // starting from first ele is in dec.
                }
            } else return 0;
        }
        return cnt == 3 ? 1 : 0;
    }
};
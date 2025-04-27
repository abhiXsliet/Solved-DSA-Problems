// https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cntSubArr = 0;
        int i = 0, j = 2;
        while (j < n) {
            if (nums[i] + nums[j] == (nums[i + 1] / 2) && (nums[i + 1] % 2 == 0)) {
                cntSubArr += 1;
            }
            i ++, j ++;
        }
        return cntSubArr;
    }
};
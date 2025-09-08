// https://leetcode.com/contest/weekly-contest-466/problems/minimum-operations-to-equalize-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool allEqual = true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[0]) {
                allEqual = false;
                break;
            }
        }
        return allEqual ? 0 : 1;
    }
};
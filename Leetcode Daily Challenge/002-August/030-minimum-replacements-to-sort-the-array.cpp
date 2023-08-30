// https://leetcode.com/problems/minimum-replacements-to-sort-the-array/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N)
    // SC = O(1)
    long long solve_greedy(vector<int>& nums) {
        int n = nums.size();
        long long operationCnt = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) continue;

            // find no. of parts a digit can be divided
            int parts = nums[i] / nums[i + 1];
            if(nums[i] % nums[i + 1] != 0) parts++;

            operationCnt += parts - 1;

            // get the initial digit of parts
            nums[i] = nums[i] / parts;
        }
        return operationCnt;
    }
public:
    long long minimumReplacement(vector<int>& nums) {
        return solve_greedy(nums);
    }
};
// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();

        // Step - 1 : Sort the given array
        sort(begin(nums), end(nums));

        int oprCnt = 0;

        for (int i = n - 1; i > 0; i--) {
            if (nums[i] == nums[i - 1])
                continue;

            oprCnt += (n - i);
        }

        return oprCnt;
    }
};
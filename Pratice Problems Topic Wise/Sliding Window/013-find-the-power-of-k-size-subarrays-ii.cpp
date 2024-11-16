// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return nums;

        vector<int> result(n - k + 1, -1);
        int i = 0, j = 1;
        while (j < n) {
            while (j - 1 >= 0 && j < n && nums[j - 1] + 1 == nums[j]) {
                if (j - i + 1 == k) {
                    result[i] = nums[j];
                    i ++;
                }
                j ++;
            }
            if (j < n && nums[j] != nums[j - 1] + 1) {
                i = j;
            }
            j ++;
        }
        return result;
    }
};
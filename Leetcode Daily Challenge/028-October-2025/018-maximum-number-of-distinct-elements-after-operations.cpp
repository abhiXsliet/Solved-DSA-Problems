// https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isOverlapping(int curr, int k, int prev) {
        return curr - k <= prev;
    }

    int getValueWithinLimitK(int prevChangedValue, int curr, int k) {
        if ((1 + prevChangedValue) - curr <= k) {
            return 1 + prevChangedValue;
        } 
        return prevChangedValue;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    int approach_1(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<int> result(n);
        result[0] = nums[0] - k;
        int cntUniques = 1;

        for (int i = 1; i < n; i ++) {
            if (nums[i] == nums[i - 1]) {
                result[i] = getValueWithinLimitK(result[i - 1], nums[i], k);
            } else {
                if (isOverlapping(nums[i], k, result[i - 1])) {
                    result[i] = getValueWithinLimitK(result[i - 1], nums[i], k);
                } else { 
                    result[i] = nums[i] - k;
                }
            }
            if (result[i - 1] != result[i])
                cntUniques ++;
        }

        return cntUniques;
    }
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        return approach_1(nums, k);  
    }
};
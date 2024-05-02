// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * log(N))
    // SC : O(1)
    int approach_1(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int i = 0, j = n - 1;
        while (i < j) {
            if (-nums[i] == nums[j]) 
                return nums[j];
            else if (-nums[i] < nums[j]) j --;
            else i ++;
        }
        return -1;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int>& nums) {
        int n   = nums.size();
        
        int res = -1;
        int arr[2001] = {0};

        for (int& num : nums) {
            if (arr[-num + 1000] == 1) {
                res = max(res, abs(num));
            }
            arr[num + 1000] = 1;
        }
        return res;
    }
public:
    int findMaxK(vector<int>& nums) {
        // return approach_1(nums);

        return approach_2(nums);
    }
};
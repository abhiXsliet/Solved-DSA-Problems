// https://leetcode.com/problems/build-array-from-permutation/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    vector<int> approach_1(vector<int> &nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; i ++) {
            result[i] = nums[nums[i]];
        }
        return result;
    }

    // TC : O(N)
    // SC : O(1)
    vector<int> approach_2(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i ++) {
            nums[i] = nums[i] + (n * (nums[nums[i]] % n));
        }
        for (int i = 0; i < n; i ++) {
            nums[i] /= n;
        } 
        return nums;
    }
public:
    vector<int> buildArray(vector<int>& nums) {
        // return approach_1(nums);
        return approach_2(nums);
    }
};
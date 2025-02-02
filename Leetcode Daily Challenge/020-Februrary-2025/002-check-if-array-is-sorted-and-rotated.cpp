// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool performRotation(vector<int> sorted, vector<int>& nums, int n) {
        // step-1 : rotate on each index and compare it with sorted
        int temp = nums[0];
        for (int i = 0; i < n - 1; i ++) {
            nums[i] = nums[i + 1];
        }
        nums[n - 1] = temp;
        // step-2 : check if the sorted became the nums
        return sorted == nums;
    }

    // TC : O(N^2)
    // SC : O(N)
    bool approach_1(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(begin(nums), end(nums));   
        for (int i = 0; i < n; i ++) {  
            if (performRotation(sorted, nums, n))
                return true;
        }
        return false;
    }

    // TC : O(N)
    // SC : O(N)
    bool approach_2(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        int lastIdx = n - 1;
        for (int i = 0; i < n; i ++) {
            if (temp.empty() && nums[0] >= nums[lastIdx]) {    // sorted property violated
                temp.push_back(nums[lastIdx]);
                lastIdx --;
            } else if (!temp.empty() && temp.back() >= nums[lastIdx]) {
                temp.push_back(nums[lastIdx]);
                lastIdx --;
            }
        }
        for (int i = lastIdx; i > 0; i --) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        if (!temp.empty() && nums[0] < temp[0])
            return false;
        int len = temp.size();
        for (int i = 0; len >= 2 && i < len - 1; i ++) {
            if (temp[i] < temp[i + 1]) {
                return false;
            }
        }
        return true;
    }

    // TC : O(N)
    // SC : O(1)
    bool approach_3(vector<int>& nums) {
        int n = nums.size();
        int peakEle = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] > nums[(i + 1) % n]) {
                peakEle ++;
            }
        }
        return peakEle <= 1;
    }
public:
    bool check(vector<int>& nums) {
        // return approach_1(nums); // quadratic with space
        // return approach_2(nums); // linear with space
        return approach_3(nums);    // linear without space : track no. of peak elements return peakEle <= 1
    }
};
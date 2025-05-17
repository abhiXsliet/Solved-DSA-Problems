// https://leetcode.com/problems/sort-colors/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1, mid = 0;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low ++, mid ++;
            } else if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high --;
            } else mid ++;
        }
    }
};
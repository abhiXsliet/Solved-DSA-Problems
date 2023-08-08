// https://leetcode.com/problems/search-in-rotated-sorted-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while(low <= high) {
            int mid = low + (high - low)/2;

            if(nums[mid] == target) return mid;
            else if(nums[low] <= nums[mid]) {// left part is sorted
                if(target <= nums[mid] && target >= nums[low]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }

            } else { // right part is sorted
                if(target >= nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
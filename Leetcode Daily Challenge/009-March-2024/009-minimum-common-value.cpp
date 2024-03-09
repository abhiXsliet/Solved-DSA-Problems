// https://leetcode.com/problems/minimum-common-value/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(max(N, M)) Where N = nums1.size(), M = nums2.size()
    // SC : O(N)
    int solve_approach_1(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mpp; // you can use set also
        for (int& num : nums1) 
            mpp[num] ++;

        for (int& num : nums2) {
            if (mpp.count(num))
                return num;
        }
        return -1;
    }

    // TC : O(log(N)) Where N = nums1.size()
    bool binarySearch(vector<int>& nums1, int target) {
        int low = 0, high = nums1.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums1[mid] == target) {
                return true;
            }
            else if (nums1[mid] > target)
                high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }

    // TC : O(N*log(M)) Where N = nums1.size() & M = nums2.size()
    // SC : O(1)
    int solve_approach_2(vector<int>& nums1, vector<int>& nums2) {
        for (int& num : nums2) {
            if (binarySearch(nums1, num)) 
                return num;
        }
        return -1;
    }

    // TC : O(max(N, M))
    // SC : O(1)
    int solve_approach_3(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) i ++;
            else if (nums1[i] > nums2[j]) j ++;
            else return nums1[i];
        }
        return -1;
    }
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // return solve_approach_1(nums1, nums2);   // Hashmap

        // return solve_approach_2(nums1, nums2);   // Binary Search

        return solve_approach_3(nums1, nums2);   // 2-Pointer
    }
};
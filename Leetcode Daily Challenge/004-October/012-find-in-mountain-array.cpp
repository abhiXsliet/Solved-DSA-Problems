// https://leetcode.com/problems/find-in-mountain-array/


#include <bits/stdc++.h>
using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int find_peak(MountainArray &mountainArr) {
        int n = mountainArr.length();
        int start = 0, end = n - 1;

        while(start < end) {
            int mid = start + (end - start) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1) ) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }

        return start;
    }

    int binarySearch_left(int target, MountainArray &mountainArr, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (mountainArr.get(mid) == target) {
                return mid;
            }
            else if (mountainArr.get(mid) < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }

    int binarySearch_right(int target, MountainArray &mountainArr, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (mountainArr.get(mid) == target) {
                return mid;
            }
            else if (mountainArr.get(mid) < target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
    
    // TC = O(log(N))
    int solve_optimal_1(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int peakIdx = find_peak(mountainArr);

        // 0 to peakIdx
        int result_idx = binarySearch_left(target, mountainArr, 0, peakIdx);

        if (result_idx != -1) return result_idx;

        // peakIdx+1 to n
        result_idx = binarySearch_right(target, mountainArr, peakIdx+1, n-1);

        return result_idx;
    }

    int binarySearch(int target, MountainArray &mountainArr, int left, int right, bool increasing) {
        while(left <= right) {
            int mid = left + (right - left) / 2;

            if (mountainArr.get(mid) == target) return mid;
            else if (mountainArr.get(mid) < target) {
                if (increasing) 
                    left = mid + 1;
                else right = mid - 1;
            }
            else {
                if (increasing) 
                    right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }

    int solve_optimal_2(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int peakIdx = find_peak(mountainArr);

        // 0 to peakIdx
        int result_idx = binarySearch(target, mountainArr, 0, peakIdx, true);

        if (result_idx != -1) return result_idx;

        // peakIdx+1 to n
        return result_idx = binarySearch(target, mountainArr, peakIdx+1, n-1, false);
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // return solve_optimal_1(target, mountainArr);


        return solve_optimal_2(target, mountainArr);
    }
};
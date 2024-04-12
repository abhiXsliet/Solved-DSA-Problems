// https://leetcode.com/problems/trapping-rain-water/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N * N)
    // SC = O(1)
    int solve_brute(vector<int>& arr, int n) {
        int maxWater = 0;
        for (int i = 0; i < n; i++) {
            int leftMax = arr[i];
            for (int j = 0; j < i; j++) {
                leftMax = max(leftMax, arr[j]);
            }

            int rightMax = arr[i];
            for (int j = i + 1; j < n; j++) {
                rightMax = max(rightMax, arr[j]);
            }

            maxWater += min(leftMax, rightMax) - arr[i];
        }
        return maxWater;
    }

    // TC = O(N)
    // SC = O(N)
    int solve_better(vector<int>& arr, int n) {
        // create leftMax, rightMax array to store the max of left and right
        vector<int> leftMax(n);  // prefix
        vector<int> rightMax(n); // suffix

        // first and last element element be the maximum
        leftMax[0]      = arr[0];
        rightMax[n - 1] = arr[n - 1];

        // fill the remaining leftMax, rightMax of the array
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], arr[i]);
            
            rightMax[n - i - 1] = max(rightMax[n - i], arr[n - i - 1]);
        }

        // for (int i = n - 2; i >= 0; i--) {
        //     rightMax[i] = max(rightMax[i + 1], arr[i]);
        // }

        int maxWater = 0;
        for (int i = 0; i < n; i++) {
            maxWater += min(leftMax[i], rightMax[i]) - arr[i];
        }

        return maxWater;
    }

    // TC = O(N)
    // SC = O(1)
    // Two Pointer Approach
    int solve_optimal(vector<int>& arr, int n) {
        int left  = 0;
        int right = n - 1;

        int maxLeft  = 0;
        int maxRight = 0;

        int maxWater = 0;
        while(left <= right) {
            if (arr[left] <= arr[right]) {
                if (maxLeft <= arr[left]) {
                    maxLeft = arr[left];
                }
                else {
                    maxWater += maxLeft - arr[left];
                }
                left++;
            }
            else {
                if (maxRight <= arr[right]) {
                    maxRight = arr[right];
                }
                else {
                    maxWater += maxRight - arr[right];
                }
                right--;
            }
        }
        return maxWater;
    }
public:
    int trap(vector<int>& height) {
        // return solve_brute(height, height.size());

        // return solve_better(height, height.size());

        return solve_optimal(height, height.size());
    }
};
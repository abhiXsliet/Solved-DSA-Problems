// https://leetcode.com/problems/find-the-pivot-integer/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    int solve_1(int n) {
        int leftSum  = 0;
        for (int pivot = 1; pivot <= n; pivot++) {
            leftSum  += pivot;
            
            int rightSum = 0;
            for (int j = pivot; j <= n; j++) {
                rightSum += j;
            }

            if (leftSum == rightSum) 
                return pivot;
        }
        return -1;
    }

    // TC : O(N)
    int solve_2(int n) {
        int tSum     = (n * (n + 1)) / 2;
        int rightSum = 0;

        for (int pivot = n; pivot >= 0; pivot--) {
            rightSum += pivot;
            
            if (rightSum == tSum) {
                return pivot;
            }
            tSum -= pivot;
        }
        return -1;
    }

    // TC : O(N)
    int solve_3(int n) {
        int i = 1;
        int j = n;

        int lSum = 1;
        int rSum = n;
        
        while (i < j) {
            if (lSum < rSum) {
                i ++;
                lSum += i;
            }
            else {
                j --;
                rSum += j;
            }
        }
        return (lSum == rSum) ? i : -1;
    }

    // TC : sqrt(N)
    int solve_4(int n) {
        int tSum  = (n * (n + 1)) / 2;
        int pivot = sqrt(tSum);

        if (pivot * pivot == tSum)
            return pivot;
        return -1;
    }

    // TC : O(log(N))
    int solve_5(int n) {
        int tSum = (n * (n + 1)) / 2;
        int low  = 1;
        int high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;   // pivot

            if (mid * mid == tSum) {
                return mid;
            }
            else if (mid * mid < tSum) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
public:
    int pivotInteger(int n) {
        // return solve_1(n);   // brute -> iteration

        // return solve_2(n);   // totalSum - right ('n' natural No. sum)

        // return solve_3(n);   // Two-Pointer

        // return solve_4(n);   // Mathematical

        return solve_5(n);      // Binary Search
    }
};
// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N * log(N))
    // SC = O(1)
    // GREEDY APPROACH
    int solve_approach_1(vector<int>& arr, int n) {
        int maxi = INT_MIN;
        
        sort (begin(arr), end(arr));

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                arr[i] = 1;
            }
            else if (abs(arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        return solve_approach_1(arr, arr.size());
    }
};
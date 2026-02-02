// https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    int maxCircularSum(vector<int> &arr) {
        int maxSum = INT_MIN, currMax = 0;
        int minSum = INT_MAX, currMin = 0;
        int total = 0;
        for (int num : arr) {
            currMax = max(currMax + num, num);  // include in the prev. subarray or start a new one
            maxSum  = max(maxSum, currMax);
            
            currMin = min(currMin + num, num); 
            minSum  = min(minSum, currMin);
            
            total  += num;
        }
        return (maxSum <= 0) ? maxSum : max(maxSum, total - minSum);
    }
};
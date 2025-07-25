// https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int maxCircularSum(vector<int> &arr) {
        int total = 0;
        int maxSum = INT_MIN, currMax = 0;
        int minSum = INT_MAX, currMin = 0;
        
        for (int &num : arr) {
            currMax = max(num, currMax + num);  // max of previous-subarray_sum + curr_ele or curr_ele
            maxSum  = max(maxSum, currMax);
            
            currMin = min(num, currMin + num);  // min of previous-subarray_sum + curr_ele or curr_ele
            minSum  = min(minSum, currMin);
            
            total  += num;
        }
        
        return ((maxSum <= 0) ? maxSum : max(maxSum, total - minSum));
    }
};
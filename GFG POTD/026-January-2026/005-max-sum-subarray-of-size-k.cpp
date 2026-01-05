// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        
        int maxSum = INT_MIN, sum = 0;
        int j = 0;
        for (int i = 0; i < n; i ++) {
            sum += arr[i];
            if (i - j + 1 > k) {
                sum -= arr[j];
                j ++;
            } 
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
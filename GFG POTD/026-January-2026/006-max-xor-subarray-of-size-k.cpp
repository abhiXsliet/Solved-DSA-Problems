// https://www.geeksforgeeks.org/problems/max-xor-subarray-of-size-k/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        int j = 0;
        int maxXor = 0, xor_ = 0;
        for (int i = 0; i < n; i ++) {
            xor_ ^= arr[i];
            if (i - j + 1 > k) {
                xor_ ^= arr[j];
                j ++;
            }
            if (i - j + 1 == k) 
                maxXor = max(maxXor, xor_);
        }
        return maxXor;
    }
};
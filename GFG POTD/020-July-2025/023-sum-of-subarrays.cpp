// https://www.geeksforgeeks.org/problems/sum-of-subarrays2229/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int subarraySum(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            int val = ((n - i) * (i + 1));
            sum += (arr[i] * val);
        }
        return sum;
    }
};
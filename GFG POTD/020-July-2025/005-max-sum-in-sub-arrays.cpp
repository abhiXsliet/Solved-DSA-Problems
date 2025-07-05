// https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int maxSum(vector<int> &arr) {
        int maxi = 0;
        for (int i = 0; i < arr.size() - 1; i ++) {
            maxi = max(maxi, arr[i] + arr[i + 1]);
        }
        return maxi;
    }
};
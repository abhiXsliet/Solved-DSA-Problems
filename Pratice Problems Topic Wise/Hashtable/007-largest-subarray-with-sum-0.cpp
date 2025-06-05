// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        int len = 0;
        mpp[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            sum += arr[i];
            if (mpp.count(sum)) {
                len = max(len, i - mpp[sum]);
            } else {
                mpp[sum] = i;
            }
        }
        return len;
    }
};
// https://www.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int sum1 = 0, sum2 = 0, maxLen = 0;
        for (int i = 0; i < n; i ++) {
            sum1 += a1[i];
            sum2 += a2[i];
            
            int diff = sum1 - sum2;
            
            if (mpp.count(diff)) {
                maxLen = max(maxLen, i - mpp[diff]);
            } else {
                mpp[diff] = i;
            }
        }
        return maxLen;
    }
};
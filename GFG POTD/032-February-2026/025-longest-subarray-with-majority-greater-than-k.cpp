// https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        
        vector<int> prefix(n);
        for (int i = 0; i < n; i++) {
            int val = (arr[i] > k) ? 1 : -1;
            prefix[i] = val + (i > 0 ? prefix[i - 1] : 0);
        }

        int maxLen = 0;

        // Case 1: subarray from 0
        for (int i = 0; i < n; i++) {
            if (prefix[i] > 0)
                maxLen = i + 1;
        }

        // Step 2: monotonic decreasing stack
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            if (stk.empty() || prefix[i] < prefix[stk.back()])
                stk.push_back(i);
        }

        // Step 3: right to left
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && prefix[i] > prefix[stk.back()]) {
                maxLen = max(maxLen, i - stk.back());
                stk.pop_back();
            }
        }

        return maxLen;
    }
};
// http://geeksforgeeks.org/problems/largest-divisible-subset--170643/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N^2)
    // SC : O(N)
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.rbegin(), arr.rend()); // sort descending for lexicographically greatest

        vector<int> dp(n, 1);        // dp[i] = length of longest subset ending at i
        vector<int> prev(n, -1);     // for tracking path
        int maxLen = 1, lastIdx = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[j] % arr[i] == 0) {  // note: arr[j] > arr[i] due to descending sort
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIdx = i;
            }
        }

        // Reconstruct path
        vector<int> res;
        while (lastIdx != -1) {
            res.push_back(arr[lastIdx]);
            lastIdx = prev[lastIdx];
        }

        // Sort ascending before returning
        sort(res.begin(), res.end());
        return res;
    }
};
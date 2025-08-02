// https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> firstSeen;
        int prefix = 0;
        int maxLen = 0;
    
        for (int i = 0; i < n; ++i) {
            // transform
            int val = (arr[i] > k) ? 1 : -1;
            prefix += val;
    
            if (prefix > 0) {
                maxLen = i + 1;  // from 0 to i is valid
            } else {
                // if prefix - 1 seen before
                if (firstSeen.count(prefix - 1)) {
                    maxLen = max(maxLen, i - firstSeen[prefix - 1]);
                }
            }
    
            // store first occurrence only
            if (!firstSeen.count(prefix)) {
                firstSeen[prefix] = i;
            }
        }
    
        return maxLen;
    }
};
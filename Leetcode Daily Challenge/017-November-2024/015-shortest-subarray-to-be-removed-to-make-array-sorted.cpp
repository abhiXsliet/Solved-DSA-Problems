// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        int ptr1 = 0, ptr2 = n - 1;
        bool f1 = 1, f2 = 1;
        for (int i = 1; i < n; i ++) {
            if (f1 && arr[i] >= arr[i - 1]) {
                ptr1 = i;
            } else f1 = 0;

            if (f2 && arr[n - i - 1] <= arr[n - i]) {
                ptr2 = n - i - 1;
            } else f2 = 0;
        }

        if (ptr1 >= ptr2) return 0;
        
        int maxLen = ptr2;
        for (int i = 0; i <= ptr1; i ++) {
            while (ptr2 < n && arr[i] > arr[ptr2]) {
                ptr2 ++;
            }
            maxLen = min(maxLen, ptr2 - i - 1);
        }
        return maxLen;
    }
};
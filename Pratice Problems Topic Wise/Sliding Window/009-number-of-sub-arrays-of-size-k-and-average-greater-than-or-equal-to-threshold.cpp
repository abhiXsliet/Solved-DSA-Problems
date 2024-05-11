// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();

        int i = 0, j = 0, sum = 0, cntSubArray = 0;
        while (j < n) {
            sum += arr[j];

            int len = j - i + 1;
            if (len == k) {
                if (sum / len >= threshold) {
                    cntSubArray += 1;
                }
                sum -= arr[i];
                i ++;
            }

            j ++;
        }
        return cntSubArray;
    }
};
// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int M = 1e9 + 7;

    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int>& arr, int n) {
        vector<int> prefSum(n, arr[0]);
        for (int i = 1; i < n; i ++) {
            prefSum[i] = (arr[i] + prefSum[i - 1]);
        }
        int evenCnt = 1, oddCnt = 0, oddCntSubarrays = 0;   // even = 1 intially because of 0
        for (int i = 0; i < n; i ++) {
            if (prefSum[i] % 2) {   // ODD + EVEN = ODD
                oddCntSubarrays = (oddCntSubarrays + evenCnt) % M;
                oddCnt += 1;
            } else {    // EVEN + ODD = ODD
                oddCntSubarrays = (oddCntSubarrays + oddCnt) % M;
                evenCnt += 1;
            }
        }
        return oddCntSubarrays;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int>& arr, int n) {
        int cumm_sum = 0;
        int evenCnt = 1, oddCnt = 0, oddCntSubarrays = 0;   // even = 1 intially because of 0
        for (int i = 0; i < n; i ++) {
            cumm_sum += arr[i];
            if (cumm_sum % 2) {   // ODD + EVEN = ODD
                oddCntSubarrays = (oddCntSubarrays + evenCnt) % M;
                oddCnt += 1;
            } else {    // EVEN + ODD = ODD
                oddCntSubarrays = (oddCntSubarrays + oddCnt) % M;
                evenCnt += 1;
            }
        }
        return oddCntSubarrays;
    }
public:
    int numOfSubarrays(vector<int>& arr) {
        // return approach_1(arr, arr.size());
        return approach_2(arr, arr.size());
    }
};
// https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0, cnt = 0;
        for (int num : arr) {
            sum += num;
            cnt += mpp[sum - k];
            mpp[sum] ++;
        }
        return cnt;
    }
};
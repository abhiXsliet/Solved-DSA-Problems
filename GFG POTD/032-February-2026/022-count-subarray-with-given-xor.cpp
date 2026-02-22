// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int result = 0;
        int prefix = 0;
        for (int &val : arr) {
            prefix ^= val;
            int required = prefix ^ k;
            result += mpp[required];
            mpp[prefix] += 1;
        }
        return result;
    }
};
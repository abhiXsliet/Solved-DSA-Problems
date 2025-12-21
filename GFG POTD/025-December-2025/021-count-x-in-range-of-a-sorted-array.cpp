// https://www.geeksforgeeks.org/problems/count-x-in-range-of-a-sorted-array/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(q*log(n)) where q = queries.size() and n = arr.size()
    // SC : O(1)
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        for (vector<int> &q : queries) {
            int l = q[0];
            int r = q[1];
            int v = q[2];
            int lastOcc  = upper_bound(begin(arr) + l, begin(arr) + r + 1, v) - begin(arr);
            int firstOcc = lower_bound(begin(arr) + l, begin(arr) + r + 1, v) - begin(arr);
            result.push_back(lastOcc - firstOcc);
        }
        return result;
    }
};
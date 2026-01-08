// https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        int i = 0, j = 0;
        vector<int> result;
        while (j < n) {
            mpp[arr[j]] ++;
            if (j - i + 1 > k) {
                mpp[arr[i]] --;
                if (!mpp[arr[i]]) mpp.erase(arr[i]);
                i ++;
            }
            if (j - i + 1 == k) {
                result.push_back(mpp.size());
            }
            j ++;
        }
        return result;
    }
};
// https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        sort(begin(arr), end(arr));
        vector<vector<int>> result;
        for (vector<int>& interval : arr) {
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            } else if (result.back()[1] >= interval[0]) {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};

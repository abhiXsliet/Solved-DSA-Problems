// https://www.geeksforgeeks.org/problems/find-number-of-elements-in-range-a-b-for-each-query/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        vector<int> ans;

        // Step 1: sort array
        sort(arr.begin(), arr.end());

        // Step 2: process queries
        for (auto &q : queries) {
            int a = q[0];
            int b = q[1];

            int left  = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
            int right = upper_bound(arr.begin(), arr.end(), b) - arr.begin();

            ans.push_back(right - left);
        }

        return ans;
    }
};
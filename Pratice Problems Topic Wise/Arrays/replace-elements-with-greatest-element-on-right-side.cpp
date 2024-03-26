// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        int maxi = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            result[i] = maxi;
            maxi = max(maxi, arr[i]);
        }
        return result;
    }
};
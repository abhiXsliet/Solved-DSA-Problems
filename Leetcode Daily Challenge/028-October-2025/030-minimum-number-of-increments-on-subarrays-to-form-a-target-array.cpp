// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        int ans  = 0;
        int prev = 0;
        int curr = 0;

        for (int i = 0; i < n; i ++) {
            curr = target[i];

            if (abs(curr) > abs(prev)) {
                ans += abs(curr - prev);
            } 
            // else (abs(curr) <= abs(prev)) do nothing

            prev = curr;
        }

        return ans;
    }
};
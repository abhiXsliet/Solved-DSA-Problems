// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(K*log(N))
    // SC : O(N)
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        vector<int> positions(n), prefixSum(n);

        for (int i = 0; i < n; i ++) {
            positions[i] = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int maxFruit = 0;
        for (int d = 0; d <= k/2; d ++) {
            // case - 1 : going left first then right
            int i      = startPos - d;      // going left
            int remain = k - 2*d;       
            int j      = startPos + remain; // going right

            int left  = lower_bound(begin(positions), end(positions), i) - begin(positions);
            int right = upper_bound(begin(positions), end(positions), j) - begin(positions) - 1;

            if (left <= right) {
                int value = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruit  = max(maxFruit, value);
            }

            // case - 2 : going right first then left
            i = startPos - remain;  // going left
            j = startPos + d;       // going right

            left  = lower_bound(begin(positions), end(positions), i) - begin(positions);
            right = upper_bound(begin(positions), end(positions), j) - begin(positions) - 1;

            if (left <= right) {
                int value = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruit  = max(maxFruit, value);
            }
        }
        return maxFruit;
    }
};
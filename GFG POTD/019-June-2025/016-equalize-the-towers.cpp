// https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int getTotalCost(vector<int> &heights, vector<int>& cost, int n, int tar) {
        int costSum = 0;
        for (int i = 0; i < n; i ++) {
            costSum += (abs(heights[i] - tar) * cost[i]);
        }
        return costSum;
    }
  public:
    // TC : O(N * log(max(heights) - min(heights)))
    // SC : O(1)
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        int low  = *min_element(begin(heights), end(heights));
        int high = *max_element(begin(heights), end(heights));
        int ans  = high;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int v1  = getTotalCost(heights, cost, n, mid);
            int v2  = getTotalCost(heights, cost, n, mid + 1);
            if (v1 <= v2) {
                ans  = mid;
                high = mid;
            } else {
                low  = mid + 1;
            }
        }
        return getTotalCost(heights, cost, n, ans);
    }
};
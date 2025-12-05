// https://www.geeksforgeeks.org/problems/walls-coloring-ii--170647/1/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        
        if(k == 1 && n > 1) return -1; // impossible case
        
        vector<int> dp(k);
        for(int j = 0; j < k; j++)
            dp[j] = costs[0][j];
        
        for(int i = 1; i < n; i++) {
            int min1 = INT_MAX, min2 = INT_MAX, color1 = -1;
            
            // find smallest and second smallest in dp
            for(int c = 0; c < k; c++) {
                if(dp[c] < min1) {
                    min2 = min1;
                    min1 = dp[c];
                    color1 = c;
                } else if(dp[c] < min2) {
                    min2 = dp[c];
                }
            }
            
            vector<int> newDp(k);
            for(int c = 0; c < k; c++) {
                if(c == color1)
                    newDp[c] = costs[i][c] + min2;
                else
                    newDp[c] = costs[i][c] + min1;
            }
            dp = newDp;
        }
        
        int ans = *min_element(dp.begin(), dp.end());
        return ans;
    }
};
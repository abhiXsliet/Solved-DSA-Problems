// https://www.geeksforgeeks.org/problems/buy-stock-with-cooldown/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;

    int solve(vector<int> &prices, int i, bool isBuy, vector<vector<int>> &dp) {
        if (i >= n) return 0;
        
        if (dp[i][isBuy] != -1)
            return dp[i][isBuy];
        
        int profit = 0;
        if (isBuy) {
            int buy     = -prices[i] + solve(prices, i + 1, 0, dp);
            int skipBuy =  solve(prices, i + 1, 1, dp);
            profit      =  max(buy, skipBuy);
        } else {
            int sell     = prices[i] + solve(prices, i + 2, 1, dp);
            int skipSell = solve(prices, i + 1, 0, dp);
            profit       = max(sell, skipSell);
        }
        
        return dp[i][isBuy] = profit;
    }

    // TC : O(N)
    // SC : O(N)
    int top_down(vector<int> &prices) {
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        return solve(prices, 0, 1, dp);
    }

    // TC : O(N)
    // SC : O(N)
    int bottom_up(vector<int> &prices) {
        vector<vector<int>> dp(n + 2, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i --) {
            for (int isBuy = 0; isBuy <= 1; isBuy ++) {
                int profit = 0;
                if (isBuy) {
                    int buy     = -prices[i] + dp[i + 1][0];
                    int skipBuy = dp[i + 1][1];
                    profit      = max(buy, skipBuy);
                } else {
                    int sell     = prices[i] + dp[i + 2][1];
                    int skipSell = dp[i + 1][0];
                    profit      = max(sell, skipSell);
                }
                dp[i][isBuy] = profit;
            }
        }
        return dp[0][1];
    }

    // TC : O(N)
    // SC : O(1)
    int space_optimized(vector<int> &prices) {
        vector<int> curr(3, 0), prev1(3, 0), prev2(3, 0);
        for (int i = n - 1; i >= 0; i --) {
            for (int isBuy = 0; isBuy <= 1; isBuy ++) {
                int profit = 0;
                if (isBuy) {
                    int buy     = -prices[i] + prev1[0];
                    int skipBuy = prev1[1];
                    profit      = max(buy, skipBuy);
                } else {
                    int sell     = prices[i] + prev2[1];
                    int skipSell = prev1[0];
                    profit      = max(sell, skipSell);
                }
                curr[isBuy] = profit;
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1[1];
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        // return top_down(prices);
        // return bottom_up(prices);
        return space_optimized(prices);   
    }
};
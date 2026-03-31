// https://www.geeksforgeeks.org/problems/buy-stock-with-transaction-fee/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solveMem(vector<int>& prices, int fee, int index, int buy, vector<vector<int>>& dp) {
        if(index == prices.size())
            return 0;
        if(dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        if(buy) {
            int buying = -prices[index] + solveMem(prices, fee, index+1, 0, dp);
            int skipBuy = 0 + solveMem(prices, fee, index+1, 1, dp);
            profit = max(buying, skipBuy);
        } else {
            int sell = +prices[index] - fee + solveMem(prices, fee, index+1, 1, dp);
            int skipSell = 0 + solveMem(prices, fee, index+1, 0, dp);
            profit = max(sell, skipSell);
        }
        return dp[index][buy] = profit;
    }

    int solveTab(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int index = n-1; index>=0; index--) {
            for(int buy = 0; buy<=1; buy++) {
                int profit = 0;
                if(buy) {
                    int buying = -prices[index] + dp[index+1][0];
                    int skipBuy = 0 + dp[index+1][1];
                    profit = max(buying, skipBuy);
                } else {
                    int sell = +prices[index] - fee + dp[index+1][1];
                    int skipSell = 0 + dp[index+1][0];
                    profit = max(sell, skipSell);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

    int solveSO(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int index = n-1; index>=0; index--) {
            for(int buy = 0; buy<=1; buy++) {
                int profit = 0;
                if(buy) {
                    int buying = -prices[index] + next[0];
                    int skipBuy = 0 + next[1];
                    profit = max(buying, skipBuy);
                } else {
                    int sell = +prices[index] - fee + next[1];
                    int skipSell = 0 + next[0];
                    profit = max(sell, skipSell);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
  public:
    int maxProfit(vector<int>& prices, int fee) {
        // int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return solveMem(prices, fee, 0, 1, dp);

        // return solveTab(prices, fee);

        return solveSO(prices, fee);
    }
};